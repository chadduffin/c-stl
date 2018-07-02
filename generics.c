#include "generics.h"

void iterator_delete(ITERATOR **iterator) {
  ERROR_NULL(iterator);
  ERROR_NULL(*iterator);

  free(*iterator);

  *iterator = NULL;
}

DATA* iterator_data(ITERATOR *iterator) {
  ERROR_NULL(iterator);
  ERROR_NULL(iterator->container_);
  ERROR_NULL(iterator->next_);
  ERROR_NULL(iterator->prev_);
  ERROR_NULL(iterator->data_);

  return iterator->data_(iterator);
}

void iterator_next(ITERATOR *iterator) {
  ERROR_NULL(iterator);
  ERROR_NULL(iterator->container_);
  ERROR_NULL(iterator->next_);
  ERROR_NULL(iterator->prev_);
  ERROR_NULL(iterator->data_);

  iterator->next_(iterator);
}

void iterator_prev(ITERATOR *iterator) {
  ERROR_NULL(iterator);
  ERROR_NULL(iterator->container_);
  ERROR_NULL(iterator->next_);
  ERROR_NULL(iterator->prev_);
  ERROR_NULL(iterator->data_);

  iterator->prev_(iterator);
}

bool is_less(DATA *left, DATA *right) {
  return left->number_ < right->number_;
}

bool is_greater(DATA *left, DATA *right) {
  return left->number_ > right->number_;
}

bool key_is_less(KEY *left, KEY *right) {
  return left->number_ < right->number_;
}

unsigned int hash_string(const char *string, unsigned int bucket_count) {
  unsigned int hash = 0;

  for (unsigned int i = 0; string[i] != '\0'; i++) {
    hash = ((hash * 31) + string[i]) % bucket_count;
  }

  return hash;
}

unsigned int hash_number(const long int number, unsigned int bucket_count) {
  return abs(number) % bucket_count;
}

