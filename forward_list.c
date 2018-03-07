#include "forward_list.h"

void forward_list_create(FORWARD_LIST **forward_list) {
  ERROR_NULL(forward_list);
  
  *forward_list = (FORWARD_LIST*)(malloc(sizeof(FORWARD_LIST)));

  (*forward_list)->size_ = 0;
  (*forward_list)->head_ = NULL;
  (*forward_list)->tail_ = NULL;
}

void forward_list_delete(FORWARD_LIST **forward_list,
                         void (*f)(DATA*)) {
  ERROR_NULL(forward_list);
  ERROR_NULL(*forward_list);

  FORWARD_LIST *tmp = *forward_list;

  while ((tmp->tail_ = tmp->head_)) {
    tmp->head_ = tmp->head_->next_;

    if (f) {
      f(&(tmp->tail_->data_));
    }

    free(tmp->tail_);
  }

  free(tmp);

  *forward_list = NULL;
}

FORWARD_LIST_NODE* forward_list_back(FORWARD_LIST *forward_list) {
  ERROR_NULL(forward_list);

  return forward_list->tail_;
}

void forward_list_clear(FORWARD_LIST *forward_list,
                        void (*f)(DATA*)) {
  ERROR_NULL(forward_list);

  while ((forward_list->tail_ = forward_list->head_)) {
    forward_list->head_ = forward_list->head_->next_;

    if (f) {
      f(&(forward_list->tail_->data_));
    }

    free(forward_list->tail_);
  }
}

bool forward_list_empty(FORWARD_LIST *forward_list) {
  ERROR_NULL(forward_list);

  return !forward_list->size_;
}

FORWARD_LIST_NODE* forward_list_front(FORWARD_LIST *forward_list) {

}

void forward_list_handle(FORWARD_LIST *forward_list,
                         void (*f)(DATA*)) {
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

  if (forward_list_left->head_) {
    forward_list_left->tail_->next_ = forward_list_right->head_;
    forward_list_left->tail_ = forward_list_right->tail_;
    forward_list_left->size_ += forward_list_right->size_;
  } else {
    forward_list_left->head_ = forward_list_right->head_;
    forward_list_left->tail_ = forward_list_right->tail_;
    forward_list_left->size_ = forward_list_right->size_;
  }

  forward_list_right->head_ = NULL;
  forward_list_right->tail_ = NULL;
  forward_list_right->tail_ = 0;
}

void forward_list_pop_front(FORWARD_LIST *forward_list) {
  ERROR_NULL(forward_list);

  FORWARD_LIST_NODE *tmp = forward_list->head_;
  
  if (tmp) {
    forward_list->head_ = tmp->next_;
  }

  free(tmp);
}

void forward_list_push_front(FORWARD_LIST *forward_list,
                             KEY key, DATA data) {
  ERROR_NULL(forward_list);

  FORWARD_LIST_NODE *tmp = (FORWARD_LIST_NODE*)
                           (malloc(sizeof(FORWARD_LIST_NODE)));

  tmp->key_ = key;
  tmp->data_ = data;
  tmp->next_ = forward_list->head_;
  forward_list->head_ = tmp;
}

void forward_list_remove(FORWARD_LIST *forward_list,
                         FORWARD_LIST_NODE *forward_list_node) {
  ERROR_NULL(forward_list);
  ERROR_NULL(forward_list_node);

  FORWARD_LIST_NODE **tmp = &(forward_list->head_);

  while (*tmp) {
    if (*tmp == forward_list_node) { break; }

    tmp = &((*tmp)->next_);
  }

  *tmp = (*tmp)->next_;

  free(forward_list_node);
}

DATA* forward_list_search(FORWARD_LIST *forward_list, KEY key) {
  ERROR_NULL(forward_list);

  FORWARD_LIST_NODE *tmp = forward_list->head_;

  while (tmp) {
    if (!memcmp(&(tmp->key_), &key, sizeof(KEY))) {
      return &(tmp->data_);
    }

    tmp = tmp->next_;
  }
}

