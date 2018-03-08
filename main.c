#include "list.h"
#include "array.h"
#include "deque.h"
#include "vector.h"
#include "forward_list.h"

int main(int argc, char **argv) {
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

  return 0;
}

