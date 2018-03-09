#include "queue.h"

void queue_create(QUEUE **queue) {
  ERROR_NULL(queue);

  *queue = (QUEUE*)(malloc(sizeof(QUEUE)));

  list_create(&((*queue)->list_));
}

void queue_delete(QUEUE **queue) {
  ERROR_NULL(queue);
  ERROR_NULL(*queue);

  list_delete(&((*queue)->list_), NULL);

  free(*queue);

  *queue = NULL;
}

DATA* queue_back(QUEUE *queue) {
  ERROR_NULL(queue);
  ERROR_NULL(queue->list_);

  return list_back(queue->list_);
}

bool queue_empty(QUEUE *queue) {
  ERROR_NULL(queue);
  ERROR_NULL(queue->list_);

  return list_empty(queue->list_);
}

DATA* queue_front(QUEUE *queue) {
  ERROR_NULL(queue);
  ERROR_NULL(queue->list_);

  return list_front(queue->list_);
}

void queue_pop(QUEUE *queue) {
  ERROR_NULL(queue);
  ERROR_NULL(queue->list_);

  list_pop_front(queue->list_);
}

void queue_push(QUEUE *queue, DATA data) {
  ERROR_NULL(queue);
  ERROR_NULL(queue->list_);

  list_push_back(queue->list_, data);
}

unsigned int queue_size(QUEUE *queue) {
  ERROR_NULL(queue);
  ERROR_NULL(queue->list_);

  return list_size(queue->list_);
}

