#include "array.h"

void array_create(ARRAY **array, unsigned int size) {
  ERROR_NULL(array);
  ERROR_RANGE(size, 0, UINT_MAX - 1);

  *array = (ARRAY*)(malloc(sizeof(ARRAY)));

  (*array)->size_ = size;
  (*array)->data_ = (DATA*)(malloc(sizeof(DATA) * size));
}

void array_delete(ARRAY **array, void (*f)(DATA*)) {
  ERROR_NULL(array);
  ERROR_NULL(*array);
  ERROR_NULL((*array)->data_);

  ARRAY *tmp = *array;

  if (f) {
    for (unsigned int i = 0; i < tmp->size_; i++) {
      f(&(tmp->data_[i]));
    }
  }

  free(tmp->data_);
  free(tmp);

  *array = NULL;
}

void array_iterator_create(ITERATOR **iterator, ARRAY *array) {
  ERROR_NULL(iterator);

  *iterator = (ITERATOR*)(malloc(sizeof(ITERATOR)));

  (*iterator)->container_ = array;
  (*iterator)->next_ = (void(*)(ITERATOR*))(array_iterator_next);
  (*iterator)->prev_ = (void(*)(ITERATOR*))(array_iterator_prev);
  (*iterator)->data_ = (DATA*(*)(ITERATOR*))(array_iterator_data);
  (*iterator)->uint_ = 0;
}

DATA* array_at(ARRAY *array, unsigned int index) {
  ERROR_NULL(array);
  ERROR_NULL(array->data_);
  ERROR_RANGE(index, 0, array->size_ - 1);

  return &(array->data_[index]);
}

DATA* array_back(ARRAY *array) {
  ERROR_NULL(array);
  ERROR_NULL(array->data_);

  return &(array->data_[array->size_-1]);
}

void array_clear(ARRAY *array) {
  ERROR_NULL(array);
  ERROR_NULL(array->data_);
  
  memset(array->data_, 0, sizeof(DATA) * array->size_);
}

bool array_empty(ARRAY *array) {
  ERROR_NULL(array);

  return !array->size_;
}

void array_fill(ARRAY *array, DATA data) {
  ERROR_NULL(array);
  ERROR_NULL(array->data_);

  for (unsigned int i = 0; i < array->size_; i++) {
    array->data_[i] = data;
  }
}

DATA* array_front(ARRAY *array) {
  ERROR_NULL(array);

  return &(array->data_[0]);
}

void array_handle(ARRAY *array, void (*f)(DATA*)) {
  ERROR_NULL(array);
  ERROR_NULL(array->data_);
  ERROR_NULL(f);

  for (unsigned int i = 0; i < array->size_; i++) {
    f(&(array->data_[i]));
  }
}

unsigned int array_size(ARRAY *array) {
  ERROR_NULL(array);

  return array->size_;
}

DATA* array_iterator_data(ITERATOR *iterator) {
  ERROR_NULL(iterator);
  ERROR_NULL(iterator->container_);
  ERROR_NULL(iterator->next_);
  ERROR_NULL(iterator->prev_);
  ERROR_NULL(iterator->data_);

  ARRAY *tmp = (ARRAY*)(iterator->container_);

  ERROR_RANGE(iterator->uint_, 0, tmp->size_ - 1);

  return &(tmp->data_[iterator->uint_]);
}

void array_iterator_next(ITERATOR *iterator) {
  ERROR_NULL(iterator);
  ERROR_NULL(iterator->container_);
  ERROR_NULL(iterator->next_);
  ERROR_NULL(iterator->prev_);
  ERROR_NULL(iterator->data_);

  ARRAY *tmp = (ARRAY*)(iterator->container_);
  
  if (iterator->uint_ < tmp->size_) {
    iterator->uint_ += 1;
  }
}

void array_iterator_prev(ITERATOR *iterator) {
  ERROR_NULL(iterator);
  ERROR_NULL(iterator->container_);
  ERROR_NULL(iterator->next_);
  ERROR_NULL(iterator->prev_);
  ERROR_NULL(iterator->data_);
  
  if (iterator->uint_ > 0) {
    iterator->uint_ -= 1;
  }
}

