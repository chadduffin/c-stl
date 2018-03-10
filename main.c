#include "list.h"
#include "array.h"
#include "stack.h"
#include "deque.h"
#include "vector.h"
#include "forward_list.h"

int main(int argc, char **argv) {

  DATA data;
  DEQUE *deque = NULL;

  deque_create(&deque);
    
  for (unsigned int i = 0; i < 10000; i++) {
    data.my_int = i;
    unsigned int j = (deque->size_ > 0) ? ((i * 0x4f1) >> (i % 100)) % deque->size_ : 0;
    deque_insert(deque, data, j);
  }

  deque_erase(deque, 9999);
  deque_erase(deque, 1000);
  deque_erase(deque, 100);
  deque_erase(deque, 10);

  for (unsigned int i = 0; i < deque_size(deque); i++) {
    printf("%i\n", deque_at(deque, i)->my_int);
  }

  deque_delete(&deque, NULL);
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

