#include "generics.h"

void iterator_delete(ITERATOR **iterator) {
  ERROR_NULL(iterator);
  ERROR_NULL(*iterator);

  free(*iterator);

  *iterator = NULL;
}

bool iterator_compare(ITERATOR *left, ITERATOR *right) {
  // compare iterators
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

