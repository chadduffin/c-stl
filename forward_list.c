#include "forward_list.h"

void forward_list_create(FORWARD_LIST **forward_list) {
  ERROR_NULL(forward_list);
  
  *forward_list = (FORWARD_LIST*)(malloc(sizeof(FORWARD_LIST)));

  (*forward_list)->head_ = NULL;
}

void forward_list_delete(FORWARD_LIST **forward_list,
                         void (*f)(DATA*)) {
  ERROR_NULL(forward_list);
  ERROR_NULL(*forward_list);

  FORWARD_LIST_NODE *tmp = NULL;

  while ((tmp = (*forward_list)->head_)) {
    (*forward_list)->head_ = tmp->next_;

    if (f) {
      f(&(tmp->data_));
    }

    free(tmp);
  }

  free(*forward_list);

  *forward_list = NULL;
}

void forward_list_clear(FORWARD_LIST *forward_list, void (*f)(DATA*)) {
  ERROR_NULL(forward_list);

  FORWARD_LIST_NODE *tmp = NULL;

  while ((tmp = forward_list->head_)) {
    forward_list->head_ = tmp->next_;

    if (f) {
      f(&(tmp->data_));
    }

    free(tmp);
  }
}

bool forward_list_empty(FORWARD_LIST *forward_list) {
  ERROR_NULL(forward_list);

  return !(forward_list->head_);
}

DATA* forward_list_front(FORWARD_LIST *forward_list) {
  ERROR_NULL(forward_list);
  ERROR_NULL(forward_list->head_);
  
  return &(forward_list->head_->data_);
}

void forward_list_handle(FORWARD_LIST *forward_list, void (*f)(DATA*)) {
  ERROR_NULL(forward_list);
  ERROR_NULL(f);

  FORWARD_LIST_NODE *tmp = forward_list->head_;

  while (tmp) {
    f(&(tmp->data_));

    tmp = tmp->next_;
  }
}

void forward_list_merge(FORWARD_LIST *forward_list_left,
                        FORWARD_LIST *forward_list_right) {
  ERROR_NULL(forward_list_left);
  ERROR_NULL(forward_list_right);

  FORWARD_LIST_NODE *tmp = forward_list_left->head_;

  if (!tmp) {
    forward_list_left->head_ = forward_list_right->head_;
  } else {
    while (tmp->next_) {
      tmp = tmp->next_;
    }

    tmp->next_ = forward_list_right->head_;
  }

  forward_list_right->head_ = NULL;
}

void forward_list_pop_front(FORWARD_LIST *forward_list) {
  ERROR_NULL(forward_list);
  ERROR_NULL(forward_list->head_);

  FORWARD_LIST_NODE *tmp = forward_list->head_;
  
  if (tmp) {
    forward_list->head_ = tmp->next_;
    free(tmp);
  }
}

void forward_list_push_front(FORWARD_LIST *forward_list, DATA data) {
  ERROR_NULL(forward_list);

  FORWARD_LIST_NODE *tmp = (FORWARD_LIST_NODE*)
                           (malloc(sizeof(FORWARD_LIST_NODE)));

  tmp->data_ = data;
  tmp->next_ = forward_list->head_;
  forward_list->head_ = tmp;
}

void forward_list_remove(FORWARD_LIST *forward_list, DATA data) {
  ERROR_NULL(forward_list);

  FORWARD_LIST_NODE *tmp = NULL, **indirect = &(forward_list->head_);

  while ((tmp = *indirect)) {
    if (memcmp(&(tmp->data_), &data, sizeof(DATA))) {
      *indirect = (*indirect)->next_;

      free(tmp);

      return;
    }

    indirect = &((*indirect)->next_);
  }
}
