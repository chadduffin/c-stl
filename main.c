#include "list.h"
#include "array.h"
#include "vector.h"
#include "forward_list.h"

void output_list(LIST *list) {
  LIST_NODE *tmp = list->head_;

  while (tmp) {
    if (tmp->next_) {
      printf("(%i) -> ", tmp->data_.my_int);
    } else {
      printf("(%i)\n", tmp->data_.my_int);
    }

    tmp = tmp->next_;
  }
}

void output_list_r(LIST *list) {
  LIST_NODE *tmp = list->tail_;

  while (tmp) {
    if (tmp->prev_) {
      printf("(%i) -> ", tmp->data_.my_int);
    } else {
      printf("(%i)\n", tmp->data_.my_int);
    }

    tmp = tmp->prev_;
  }
}

void multiply_by_two(DATA *data) {
  data->my_int *= 2;
}

int main(int argc, char **argv) {
  LIST *a = NULL, *b = NULL;
  DATA data;

  list_create(&a);
  list_create(&b);

  for (unsigned int i = 0; i < 5; i++) {
    data.my_int = i;
    list_push_front(a, data);
  }

  for (unsigned int i = 5; i < 10; i++) {
    data.my_int = i;
    list_push_front(b, data);
  }

  output_list(a);
  output_list(b);
  output_list_r(a);
  output_list_r(b);

  printf("Front of a: %i\n", list_front(a)->my_int);
  printf("Front of b: %i\n", list_front(b)->my_int);
  printf("Back of a: %i\n", list_back(a)->my_int);
  printf("Back of b: %i\n", list_back(b)->my_int);

  list_handle(a, multiply_by_two);

  output_list(a);
  output_list_r(a);

  list_merge(a, b);

  output_list(a);
  output_list(b);

  if (list_empty(b)) {
    printf("b is empty\n");
  }

  list_pop_back(a);
  list_pop_back(a);
  list_pop_front(a);
  list_pop_front(a);

  output_list(a);
  output_list_r(a);

  data.my_int = 7;
  list_remove(a, data);
  data.my_int = 0;
  list_remove(a, data);
  data.my_int = 4;
  list_remove(a, data);

  output_list(a);
  output_list_r(a);

  list_delete(&a, NULL);
  list_delete(&b, NULL);

  return 0;
}

