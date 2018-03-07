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

  VECTOR *tmp = *vector;

  array_delete(&(tmp->array_), f);

  free(tmp);

  *vector = NULL;
}

DATA* vector_at(VECTOR *vector, unsigned int index) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  ERROR_RANGE(index, 0, vector->size_);

  return &(vector->array_->data_[index]);
}

DATA* vector_back(VECTOR *vector) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);

  return &(vector->array_->data_[vector->size_-1]);
}

unsigned int vector_capacity(VECTOR *vector) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  
  return vector->array_->size_;
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
  ERROR_RANGE(index, 0, vector->size_);

  for (unsigned int i = index; i < vector->size_-1; i++) {
    vector->array_->data_[i] = vector->array_->data_[i+1];
  }

  vector->size_ -= 1;
}

DATA* vector_front(VECTOR *vector) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);

  return &(vector->array_->data_[0]);
}

void vector_handle(VECTOR *vector, void (*f)(DATA*)) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  ERROR_NULL(f);

  for (unsigned int i = 0; i < vector->size_; i++) {
    f(&(vector->array_->data_[i]));
  }
}

void vector_insert(VECTOR *vector, DATA data, unsigned int index) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  ERROR_RANGE(index, 0, vector->size_);

  ARRAY *tmp = NULL;

  if (vector->size_+1 >= vector->array_->size_) {
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

  if (vector->size_ >= vector->array_->size_) {
    ARRAY *tmp = NULL;

    array_create(&tmp, vector->array_->size_ * VECTOR_RESIZE_RELATION);

    for (unsigned int i = 0; i < vector->size_; i++) {
      tmp->data_[i] = vector->array_->data_[i];
    }

    array_delete(&(vector->array_), NULL);

    vector->array_ = tmp;
  }

  vector->array_->data_[vector->size_] = data;
  vector->size_ += 1;
}

void vector_resize(VECTOR *vector, unsigned int size) {
  ERROR_NULL(vector);
  ERROR_NULL(vector->array_);
  ERROR_RANGE(size, 0, UINT_MAX);

  if (size > vector->array_->size_) {
    ARRAY *tmp = NULL;

    array_create(&tmp, size);

    for (unsigned int i = 0; i < vector->size_; i++) {
      tmp->data_[i] = vector->array_->data_[i];
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

