#include "priority_queue.h"

void priority_queue_create(PRIORITY_QUEUE **priority_queue, bool (*cmp)(DATA*, DATA*)) {
  ERROR_NULL(priority_queue);
  ERROR_NULL(cmp);

  *priority_queue = (PRIORITY_QUEUE*)(malloc(sizeof(PRIORITY_QUEUE)));

  (*priority_queue)->cmp_ = cmp;

  vector_create(&((*priority_queue)->vector_));
}

void priority_queue_delete(PRIORITY_QUEUE **priority_queue) {
  ERROR_NULL(priority_queue);
  ERROR_NULL(*priority_queue);
  ERROR_NULL((*priority_queue)->vector_);

  vector_delete(&((*priority_queue)->vector_), NULL);

  free(*priority_queue);

  *priority_queue = NULL;
}

bool priority_queue_empty(PRIORITY_QUEUE *priority_queue) {
  ERROR_NULL(priority_queue);
  ERROR_NULL(priority_queue->vector_);

  return vector_empty(priority_queue->vector_);
}

void priority_queue_pop(PRIORITY_QUEUE *priority_queue) {
  ERROR_NULL(priority_queue);
  ERROR_NULL(priority_queue->vector_);
  ERROR_ZERO(priority_queue->vector_->size_)

  bool left = false, right = false;
  unsigned int parent = 0, left_child = 1, right_child = 2,
               size = vector_size(priority_queue->vector_) - 1;

  vector_swap(priority_queue->vector_, 0, size);
  vector_pop_back(priority_queue->vector_);

  while (parent < size) {
    left_child = (parent * 2) + 1;
    right_child = (parent * 2) + 2;

    if ((left_child < size) &&
        (priority_queue->cmp_(vector_at(priority_queue->vector_, left_child),
                              vector_at(priority_queue->vector_, parent)))) {
      left = true;
    } else {
      left = false;
    }

    if ((right_child < size) &&
        (priority_queue->cmp_(vector_at(priority_queue->vector_, right_child),
                              vector_at(priority_queue->vector_, parent)))) {
      right = true;
    } else {
      right = false;
    }

    if ((right) && (left)) {
      if (priority_queue->cmp_(vector_at(priority_queue->vector_, right_child),
                               vector_at(priority_queue->vector_, left_child))) {
        vector_swap(priority_queue->vector_, right_child, parent);
        parent = right_child;
      } else {
        vector_swap(priority_queue->vector_, left_child, parent);
        parent = left_child;
      }
    } else if (right) {
      vector_swap(priority_queue->vector_, right_child, parent);
      parent = right_child;
    } else if (left) {
      vector_swap(priority_queue->vector_, left_child, parent);
      parent = left_child;
    } else {
      break;
    }
  }
}

void priority_queue_push(PRIORITY_QUEUE *priority_queue, DATA data) {
  ERROR_NULL(priority_queue);
  ERROR_NULL(priority_queue->vector_);

  unsigned int child = vector_size(priority_queue->vector_), parent = 0;

  vector_push_back(priority_queue->vector_, data);

  while (child > 0) {
    parent = (child - 1) / 2;

    if (priority_queue->cmp_(vector_at(priority_queue->vector_, child),
                             vector_at(priority_queue->vector_, parent))) {
      vector_swap(priority_queue->vector_, child, parent);
      child = parent;
    } else {
      break;
    }
  }
}

unsigned int priority_queue_size(PRIORITY_QUEUE *priority_queue) {
  ERROR_NULL(priority_queue);
  ERROR_NULL(priority_queue->vector_);

  return vector_size(priority_queue->vector_);
}

DATA* priority_queue_top(PRIORITY_QUEUE *priority_queue) {
  ERROR_NULL(priority_queue);
  ERROR_NULL(priority_queue->vector_);
  ERROR_ZERO(priority_queue->vector_->size_);

  return vector_front(priority_queue->vector_);
}

