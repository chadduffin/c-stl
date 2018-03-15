#include "list.h"
#include "array.h"
#include "stack.h"
#include "deque.h"
#include "vector.h"
#include "forward_list.h"
#include "priority_queue.h"

int main(int argc, char **argv) {

  DATA data;
  PRIORITY_QUEUE *priority_queue = NULL;

  priority_queue_create(&priority_queue, is_less);

  for (unsigned int i = 0; i < 11; i++) {
    data.my_int = i;
    priority_queue_push(priority_queue, data);
  }

  for (unsigned int i = 20; i > 10; i--) {
    data.my_int = i;
    priority_queue_push(priority_queue, data);
  }

  for (unsigned int i = 21; i < 31; i++) {
    data.my_int = i;
    priority_queue_push(priority_queue, data);
  }

  for (unsigned int i = 40; i > 30; i--) {
    data.my_int = i;
    priority_queue_push(priority_queue, data);
  }

  for (unsigned int i = 41; i < 50; i++) {
    data.my_int = i;
    priority_queue_push(priority_queue, data);
  }

  printf("size %u\n", priority_queue_size(priority_queue));

  for (unsigned int i = 0; i < 50; i++) {
    printf("top %i\n", priority_queue_top(priority_queue)->my_int);
    priority_queue_pop(priority_queue);
  }

  priority_queue_delete(&priority_queue);
/*
  ARRAY *array = NULL;
  ITERATOR *iterator = NULL;

  array_create(&array, 10);
  array_iterator_create(&iterator, array);

  for (unsigned int i = 0; i < 10; i++) {
    array_at(array, i)->my_int = i;
  }

  while (1) {
    printf("%i\n", iterator_data(iterator)->my_int);

    if (iterator->uint_ == 9) { break; }

    iterator_next(iterator);
  }

  iterator_delete(&iterator);
  array_delete(&array, NULL);
*/
  return 0;
}

