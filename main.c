#include "array.h"

void multiply_by_two(DATA *data) {
  data->my_int *= 2;
}

int main(int argc, char **argv) {
  ARRAY *array = NULL;

  // create an array of size 10
  array_create(&array, 10);

  // set array values
  for (unsigned int i = 0; i < array_size(array); i++) {
    array_at(array, i)->my_int = i;
  }

  // output array values
  for (unsigned int i = 0; i < array_size(array); i++) {
    printf("%i\n", array_at(array, i)->my_int);
  }

  // output front
  printf("%i\n", array_front(array)->my_int);

  // output back
  printf("%i\n", array_back(array)->my_int);

  if (!array_empty(array)) {
    printf("not empty!\n");
  }

  array_handle(array, multiply_by_two);

  // output array values
  for (unsigned int i = 0; i < array_size(array); i++) {
    printf("%i\n", array_at(array, i)->my_int);
  }

  array_clear(array);

  // output array values
  for (unsigned int i = 0; i < array_size(array); i++) {
    printf("%i\n", array_at(array, i)->my_int);
  }

  array_delete(&array, NULL);

  return 0;
}
