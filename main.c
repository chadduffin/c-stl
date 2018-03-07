#include "array.h"
#include "vector.h"

void multiply_by_two(DATA *data) {
  data->my_int *= 2;
}

int main(int argc, char **argv) {
  VECTOR *vector = NULL;

  vector_create(&vector);

  DATA data;

  for (unsigned int i = 0; i < 32; i++) {
    data.my_int = i;
    vector_push_back(vector, data);
    printf("size: %i\n", vector_capacity(vector));
  }

  data.my_int = -1;

  vector_insert(vector, data, 5);
  vector_insert(vector, data, 10);
  vector_insert(vector, data, 20);
  vector_insert(vector, data, 35);

  for (unsigned int i = 0; i < vector_size(vector); i++) {
    printf("%i\n", vector_at(vector, i)->my_int);
  }

  printf("size: %u, capacity: %u\n", vector_size(vector), vector_capacity(vector));

  vector_erase(vector, 35);
  vector_erase(vector, 20);
  vector_erase(vector, 10);
  vector_erase(vector, 5);

  for (unsigned int i = 30; i > 0; i -= 5) {
    vector_erase(vector, i);
  }

  for (unsigned int i = 0; i < vector_size(vector); i++) {
    printf("%i\n", vector_at(vector, i)->my_int);
  }

  printf("front: %u\n", vector_front(vector)->my_int);
  printf("back: %u\n", vector_back(vector)->my_int);

  vector_handle(vector, multiply_by_two);

  for (unsigned int i = 0; i < vector_size(vector); i++) {
    printf("%i\n", vector_at(vector, i)->my_int);
  }

  vector_pop_back(vector);
  vector_pop_back(vector);
  vector_pop_back(vector);
  vector_pop_back(vector);
  vector_pop_back(vector);

  for (unsigned int i = 0; i < vector_size(vector); i++) {
    printf("%i\n", vector_at(vector, i)->my_int);
  }

  vector_resize(vector, 5);

  for (unsigned int i = 0; i < vector_size(vector); i++) {
    printf("%i\n", vector_at(vector, i)->my_int);
  }

  vector_clear(vector);

  printf("cleared\n");

  for (unsigned int i = 0; i < vector_size(vector); i++) {
    printf("%i\n", vector_at(vector, i)->my_int);
  }

  vector_delete(&vector, NULL);

  return 0;
}
