#include "array.h"
#include "vector.h"
#include "forward_list.h"

void output_forward_list(FORWARD_LIST *list) {
  FORWARD_LIST_NODE *tmp = list->head_;

  while (tmp) {
    if (tmp->next_) {
      printf("(data: %i) -> ", tmp->data_.my_int);
    } else {
      printf("(data: %i)\n", tmp->data_.my_int);
    }

    tmp = tmp->next_;
  }
}

int main(int argc, char **argv) {
  DATA data;
  FORWARD_LIST *list = NULL, *other_list = NULL;

  forward_list_create(&list);
  forward_list_create(&other_list);

  for (unsigned int i = 0; i < 5; i++) {
    data.my_int = i;

    forward_list_push_front(list, data);
  }

  for (unsigned int i = 100; i < 105; i++) {
    data.my_int = i;

    forward_list_push_front(other_list, data);
  }

  output_forward_list(list);

  data.my_int = 2;

  forward_list_remove(list, data);

  output_forward_list(list);
  output_forward_list(other_list);

  forward_list_merge(list, other_list);

  output_forward_list(list);
  output_forward_list(other_list);

  printf("back: %i\n", forward_list_back(list)->my_int);
  printf("front: %i\n", forward_list_front(list)->my_int);

  printf("the list is %sempty\n", (forward_list_empty(list)) ? "" : "not ");

  forward_list_pop_front(list);
  forward_list_pop_front(list);
  forward_list_pop_front(list);

  output_forward_list(list);

  forward_list_delete(&list, NULL);

  return 0;
}
