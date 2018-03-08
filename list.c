#include "list.h"

void list_create(LIST **list) {
  ERROR_NULL(list);

  *list = (LIST*)(malloc(sizeof(LIST)));

  (*list)->head_ = NULL;
  (*list)->tail_ = NULL;
}

void list_delete(LIST **list, void (*f)(DATA*)) {
  ERROR_NULL(list);
  ERROR_NULL(*list);

  LIST *tmp = *list;

  while ((tmp->tail_ = tmp->head_)) {
    tmp->head_ = tmp->head_->next_;

    if (f) {
      f(&(tmp->tail_->data_));
    }

    free(tmp->tail_);
  }

  free(tmp);

  *list = NULL;
}

DATA* list_back(LIST *list) {
  ERROR_NULL(list);

  return (list->tail_) ? &(list->tail_->data_) : NULL;
}

void list_clear(LIST *list, void (*f)(DATA*)) {
  ERROR_NULL(list);

  while ((list->tail_ = list->head_)) {
    list->head_ = list->head_->next_;

    if (f) {
      f(&(list->tail_->data_));
    }

    free(list->tail_);
  }

  list->head_ = NULL;
  list->tail_ = NULL;
}

bool list_empty(LIST *list) {
  ERROR_NULL(list);

  return !(list->head_);
}

DATA* list_front(LIST *list) {
  ERROR_NULL(list);

  return (list->head_) ? &(list->head_->data_) : NULL;
}

void list_handle(LIST *list, void (*f)(DATA*)) {
  ERROR_NULL(list);
  ERROR_NULL(f);

  LIST_NODE *tmp = list->head_;

  while (tmp) {
    f(&(tmp->data_));

    tmp = tmp->next_;
  }
}

void list_merge(LIST *list_left, LIST *list_right) {
  ERROR_NULL(list_left);
  ERROR_NULL(list_right);

  if (list_left->head_) {
    list_left->tail_->next_ = list_right->head_;
    list_right->head_->prev_ = list_left->tail_;
    list_left->tail_ = list_right->tail_;
  } else {
    list_left->head_ = list_right->head_;
    list_left->tail_ = list_right->tail_;
  }

  list_right->head_ = NULL;
  list_right->tail_ = NULL;
}

void list_pop_back(LIST *list) {
  ERROR_NULL(list);

  LIST_NODE *tmp = NULL;

  if ((tmp = list->tail_)) {
    list->tail_ = list->tail_->prev_;
    list->tail_->next_ = NULL;

    free(tmp);
  }
}

void list_pop_front(LIST *list) {
  ERROR_NULL(list);

  LIST_NODE *tmp = NULL;

  if ((tmp = list->head_)) {
    list->head_ = list->head_->next_;
    list->head_->prev_ = NULL;

    free(tmp);
  }
}

void list_push_back(LIST *list, DATA data) {
  ERROR_NULL(list);

  LIST_NODE *tmp = (LIST_NODE*)(malloc(sizeof(LIST_NODE)));

  tmp->data_ = data;
  tmp->next_ = NULL;
  
  if ((tmp->prev_ = list->tail_)) {
    list->tail_->next_ = tmp;
    list->tail_ = tmp;
  } else {
    list->head_ = tmp;
    list->tail_ = tmp;
  }
}

void list_push_front(LIST *list, DATA data) {
  ERROR_NULL(list);

  LIST_NODE *tmp = (LIST_NODE*)(malloc(sizeof(LIST_NODE)));

  tmp->data_ = data;
  tmp->prev_ = NULL;
  
  if ((tmp->next_ = list->head_)) {
    list->head_->prev_ = tmp;
    list->head_ = tmp;
  } else {
    list->head_ = tmp;
    list->tail_ = tmp;
  }
}

void list_remove(LIST *list, DATA data) {
  ERROR_NULL(list);

  LIST_NODE *tmp = NULL, **indirect = &(list->head_);

  while ((tmp = *indirect)) {
    if (!memcmp(&(tmp->data_), &data, sizeof(DATA))) {
      if (tmp->next_) {
        tmp->next_->prev_ = tmp->prev_;
      } else if (tmp == list->tail_) {
        list->tail_ = tmp->prev_;
      }

      *indirect = (*indirect)->next_;

      free(tmp);

      return;
    }

    indirect = &((*indirect)->next_);
  }
}

