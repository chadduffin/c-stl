#include "vector.h"

void vector_create(VECTOR **vector) {
  ERROR_NULL(vector);

  *vector = (VECTOR*)(malloc(sizeof(VECTOR)));
  
  (*vector)->size_ = 0;
  
  array_create(&((*vector)->array_), VECTOR_INIT_SIZE);
}

void vector_delete(VECTOR **vector, void (*f)(DATA*)) {
  ERROR_NULL(vector);
  ERROR_NULL(*vector);
  ERROR_NULL((*vector)->array_);

  array_delete(&((*vector)->array_), f);

  free(*vector);

  *vector = NULL;
}

DATA* vector_at(VECTOR *vector, unsigned int index) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  ERROR_RANGE(index, 0, vector->size_ - 1);

  return array_at(vector->array_, index);
}

DATA* vector_back(VECTOR *vector) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  ERROR_ZERO(vector->size_);

  return array_at(vector->array_, vector->size_ - 1);
}

unsigned int vector_capacity(VECTOR *vector) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  
  return array_size(vector->array_);
}

void vector_clear(VECTOR *vector) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  
  array_delete(&(vector->array_), NULL);
  array_create(&(vector->array_), VECTOR_INIT_SIZE);

  vector->size_ = 0;
}

bool vector_empty(VECTOR *vector) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  
  return !vector->size_;
}

void vector_erase(VECTOR *vector, unsigned int index) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  ERROR_RANGE(index, 0, vector->size_ - 1);

  for (unsigned int i = index; i < vector->size_ - 1; i++) {
    *(array_at(vector->array_, i)) = *(array_at(vector->array_, i + 1));
  }

  vector->size_ -= 1;
}

DATA* vector_front(VECTOR *vector) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);

  return array_at(vector->array_, 0);
}

void vector_handle(VECTOR *vector, void (*f)(DATA*)) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  ERROR_NULL(f);

  array_handle(vector->array_, f);
}

void vector_insert(VECTOR *vector, DATA data, unsigned int index) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  ERROR_RANGE(index, 0, vector->size_ - 1);

  ARRAY *tmp = NULL;

  if (vector->size_ >= vector->array_->size_) {
    array_create(&tmp, vector->array_->size_ * VECTOR_RESIZE_RELATION);
  } else {
    tmp = vector->array_;
  }

  for (unsigned int i = vector->size_;; i--) {
    if (i < index) {
      tmp->data_[i] = vector->array_->data_[i];
    } else if (i > index) {
      tmp->data_[i] = vector->array_->data_[i-1];
    } else {
      tmp->data_[i] = data;
    }

    if (i == 0) { break; }
  }

  if (vector->array_ != tmp) {
    array_delete(&(vector->array_), NULL);
  }

  vector->array_ = tmp;
  vector->size_ += 1;
}

void vector_pop_back(VECTOR *vector) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);

  vector->size_ -= 1;
}

void vector_push_back(VECTOR *vector, DATA data) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);

  if (vector->size_ >= array_size(vector->array_)) {
    ARRAY *tmp = NULL;

    array_create(&tmp, array_size(vector->array_) * VECTOR_RESIZE_RELATION);

    for (unsigned int i = 0; i < vector->size_; i++) {
      *(array_at(tmp, i)) = *(array_at(vector->array_, i));
    }

    array_delete(&(vector->array_), NULL);

    vector->array_ = tmp;
  }

  *(array_at(vector->array_, vector->size_)) = data;
  vector->size_ += 1;
}

void vector_resize(VECTOR *vector, unsigned int size) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  ERROR_RANGE(size, 0, UINT_MAX - 1);

  if (size > vector->array_->size_) {
    ARRAY *tmp = NULL;

    array_create(&tmp, size);

    for (unsigned int i = 0; i < vector->size_; i++) {
      *(array_at(tmp, i)) = *(array_at(vector->array_, i));
    }

    array_delete(&(vector->array_), NULL);

    vector->array_ = tmp;
  }

  vector->size_ = size;
}

unsigned int vector_size(VECTOR *vector) {
  ERROR_NULL(vector);

  return vector->size_;
}

