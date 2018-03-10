#include "deque.h"

void deque_create(DEQUE **deque) {
  ERROR_NULL(deque);

  *deque = (DEQUE*)(malloc(sizeof(DEQUE)));

  (*deque)->size_ = 0;
  (*deque)->head_ = UINT_MAX;
  (*deque)->tail_ = UINT_MAX;
  (*deque)->length_ = 1;
  (*deque)->segments_ = (ARRAY**)(malloc(sizeof(ARRAY*)));

  array_create(&((*deque)->segments_[0]), DEQUE_SEGMENT_SIZE);
}

void deque_delete(DEQUE **deque, void (*f)(DATA*)) {
  ERROR_NULL(deque);
  ERROR_NULL(*deque);
  ERROR_NULL((*deque)->segments_);

  DEQUE *tmp = *deque;

  for (unsigned int i = 0; i < tmp->length_; i++) {
    array_delete(&(tmp->segments_[i]), f);
  }

  free(tmp->segments_);
  free(tmp);

  *deque = NULL;
}

DATA* deque_at(DEQUE *deque, unsigned int index) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);
  ERROR_RANGE(index, 0, deque->size_ - 1);

  unsigned int segment_index = index + deque->head_;

  index = segment_index % DEQUE_SEGMENT_SIZE;
  segment_index = segment_index / DEQUE_SEGMENT_SIZE;

  return &(deque->segments_[segment_index]->data_[index]);
}

DATA* deque_back(DEQUE *deque) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);
  ERROR_ZERO(deque->size_);

  unsigned int index = deque->tail_ % DEQUE_SEGMENT_SIZE;

  return &(deque->segments_[deque->length_ - 1]->data_[index]);
}

unsigned int deque_capacity(DEQUE *deque) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);

  return deque->length_ * DEQUE_SEGMENT_SIZE;
}

void deque_clear(DEQUE *deque) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);

  for (unsigned int i = 0; i < deque->length_; i++) {
    array_delete(&(deque->segments_[i]), NULL);
  }

  free(deque->segments_);

  deque->size_ = 0;
  deque->head_ = UINT_MAX;
  deque->tail_ = UINT_MAX;
  deque->length_ = 1;
  deque->segments_ = (ARRAY**)(malloc(sizeof(ARRAY*)));

  array_create(&(deque->segments_[0]), DEQUE_SEGMENT_SIZE);
}

bool deque_empty(DEQUE *deque) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);

  return !deque->size_;
}

void deque_erase(DEQUE *deque, unsigned int index) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);
  ERROR_RANGE(index, 0, deque->size_ - 1);

  int inc = 1;
  unsigned int begin = index + deque->head_, end = 0, segment_index = 0;
  DATA *tmp = NULL;

  if (index >= (deque->size_ / 2)) {
    end = deque->tail_;
    inc = 1;
  } else {
    end = deque->head_;
    inc = -1;
  }

  index = begin % DEQUE_SEGMENT_SIZE;
  segment_index = begin / DEQUE_SEGMENT_SIZE;

  for (unsigned int i = begin;; i += inc) {
    if (tmp) {
      *tmp = deque->segments_[segment_index]->data_[index];
    }

    tmp = &(deque->segments_[segment_index]->data_[index]);

    if (((inc == 1) && (i >= end)) || ((inc == -1) && (i <= end))) {
      break;
    }

    if ((inc == -1) && (index == 0)) {
      index = DEQUE_SEGMENT_SIZE - 1;
      segment_index -= 1;
    } else if ((inc == 1) && (index == DEQUE_SEGMENT_SIZE - 1)) {
      index = 0;
      segment_index += 1;
    } else {
      index += inc;
    }
  }

  if (inc == -1) {
    deque_pop_front(deque);
  } else {
    deque_pop_back(deque);
  }
}

DATA* deque_front(DEQUE *deque) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);
  ERROR_ZERO(deque->size_);

  return &(deque->segments_[0]->data_[deque->head_]);
}

void deque_handle(DEQUE *deque, void (*f)(DATA*)) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);
  ERROR_NULL(f);

  unsigned int index = deque->head_ % DEQUE_SEGMENT_SIZE,
               segment_index = deque->head_ / DEQUE_SEGMENT_SIZE;

  for (unsigned int i = deque->head_; i <= deque->tail_; i++) {
    f(&(deque->segments_[segment_index]->data_[index]));

    if ((i + 1) % DEQUE_SEGMENT_SIZE) {
      index += 1;
    } else {
      segment_index += 1;
      index = 0;
    }
  }
}

void deque_insert(DEQUE *deque, DATA data, unsigned int index) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);
  ERROR_RANGE(index, 0, deque->size_);

  int inc = 1;
  unsigned int begin = 0, end = 0, segment_index = 0;
  DATA *tmp = NULL;

  if (!deque->size_) {
    deque_push_back(deque, data);
    return;
  } else if (index >= (deque->size_ / 2)) {
    deque_push_back(deque, data);

    begin = deque->tail_;
    end = index + deque->head_;
    inc = -1;
  } else {
    deque_push_front(deque, data);

    begin = deque->head_;
    end = index + deque->head_;
    inc = 1;
  }

  index = begin % DEQUE_SEGMENT_SIZE;
  segment_index = begin / DEQUE_SEGMENT_SIZE;

  for (unsigned int i = begin;; i += inc) {
    if (tmp) {
      *tmp = deque->segments_[segment_index]->data_[index];
    }

    tmp = &(deque->segments_[segment_index]->data_[index]);

    if (((inc == 1) && (i >= end)) || ((inc == -1) && (i <= end))) {
      break;
    }

    if ((inc == -1) && (index == 0)) {
      index = DEQUE_SEGMENT_SIZE - 1;
      segment_index -= 1;
    } else if ((inc == 1) && (index == DEQUE_SEGMENT_SIZE - 1)) {
      index = 0;
      segment_index += 1;
    } else {
      index += inc;
    }
  }

  *tmp = data;
}

void deque_pop_back(DEQUE *deque) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);
  ERROR_ZERO(deque->size_);

  deque->tail_ -= 1;
  deque->size_ -= 1;

  if (!deque->size_) {
    deque->head_ = UINT_MAX;
    deque->tail_ = UINT_MAX;
  } else if (deque->tail_ < ((deque->length_ - 1) * DEQUE_SEGMENT_SIZE)) {
    ARRAY **segments = deque->segments_;

    deque->length_ -= 1;

    array_delete(&(deque->segments_[deque->length_]), NULL);

    deque->segments_ = (ARRAY**)(malloc(sizeof(ARRAY*) * (deque->length_)));

    for (unsigned int i = 0; i < deque->length_; i++) {
      deque->segments_[i] = segments[i];
    }

    free(segments);
  }
}

void deque_pop_front(DEQUE *deque) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);
  ERROR_ZERO(deque->size_);

  deque->head_ += 1;
  deque->size_ -= 1;

  if (!deque->size_) {
    deque->head_ = UINT_MAX;
    deque->tail_ = UINT_MAX;
  } else if (deque->head_ > DEQUE_SEGMENT_SIZE) {
    ARRAY **segments = deque->segments_;

    deque->head_ -= DEQUE_SEGMENT_SIZE;
    deque->tail_ -= DEQUE_SEGMENT_SIZE;
    deque->length_ -= 1;

    array_delete(&(deque->segments_[0]), NULL);

    deque->segments_ = (ARRAY**)(malloc(sizeof(ARRAY*) * (deque->length_)));

    for (unsigned int i = 0; i < deque->length_; i++) {
      deque->segments_[i] = segments[i + 1];
    }

    free(segments);
  }
}

void deque_push_back(DEQUE *deque, DATA data) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);

  if (!deque->size_) {
    deque->head_ = DEQUE_SEGMENT_SIZE / 2;
    deque->tail_ = DEQUE_SEGMENT_SIZE / 2;
    deque->segments_[0]->data_[deque->head_] = data;
  } else {
    unsigned int index = (deque->tail_ + 1) % DEQUE_SEGMENT_SIZE;

    if (deque->tail_ + 1 >= (deque->length_ * DEQUE_SEGMENT_SIZE)) {
      ARRAY **segments = deque->segments_;

      deque->length_ += 1;
      deque->segments_ = (ARRAY**)(malloc(sizeof(ARRAY*) * (deque->length_)));

      array_create(&(deque->segments_[deque->length_ - 1]), DEQUE_SEGMENT_SIZE);

      for (unsigned int i = 0; i < deque->length_ - 1; i++) {
        deque->segments_[i] = segments[i];
      }

      free(segments);

      index = 0;
    }

    deque->tail_ += 1;
    deque->segments_[deque->length_ - 1]->data_[index] = data;
  }

  deque->size_ += 1;
}

void deque_push_front(DEQUE *deque, DATA data) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);

  if (!deque->size_) {
    deque->head_ = DEQUE_SEGMENT_SIZE / 2;
    deque->tail_ = DEQUE_SEGMENT_SIZE / 2;
    deque->segments_[0]->data_[deque->head_] = data;
  } else {
    if (deque->head_ == 0) {
      ARRAY **segments = deque->segments_;

      deque->length_ += 1;
      deque->segments_ = (ARRAY**)(malloc(sizeof(ARRAY*) * (deque->length_)));

      array_create(&(deque->segments_[0]), DEQUE_SEGMENT_SIZE);

      for (unsigned int i = 0; i < deque->length_ - 1; i++) {
        deque->segments_[i + 1] = segments[i];
      }

      free(segments);

      deque->head_ += DEQUE_SEGMENT_SIZE;
      deque->tail_ += DEQUE_SEGMENT_SIZE;
    }

    deque->head_ -= 1;
    deque->segments_[0]->data_[deque->head_] = data;
  }

  deque->size_ += 1;
}

void deque_resize(DEQUE *deque, unsigned int size) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);
  ERROR_RANGE(size, 0, UINT_MAX);

  DATA data;

  while (size < deque->size_) {
    deque_pop_back(deque);
  }

  while (size > deque->size_) {
    deque_push_back(deque, data);
  }
}

unsigned int deque_size(DEQUE *deque) {
  ERROR_NULL(deque);
  ERROR_NULL(deque->segments_);

  return deque->size_;
}

