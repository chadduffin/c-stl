#include "array.h"

void array_create(ARRAY **array, unsigned int size) {
  ERROR_NULL(array);

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

DATA* array_at(ARRAY *array, int index) {
  ERROR_NULL(array);
  ERROR_NULL(array->data_);
  ERROR_RANGE(index, 0, array->size_);

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

DATA* array_fill(ARRAY *array, DATA data) {
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

  for (unsigned int i = 0; i < array->size_; i++) {
    f(&(array->data_[i]));
  }
}

unsigned int array_size(ARRAY *array) {
  ERROR_NULL(array);

  return array->size_;
}

