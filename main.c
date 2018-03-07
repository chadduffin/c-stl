#include "array.h"
#include "vector.h"

int main(int argc, char **argv) {
  VECTOR *vector = NULL;

  vector_create(&vector);

  DATA data;

  for (unsigned int i = 0; i < 1000; i++) {
    data.my_int = i;
    vector_push_back(vector, data);
  }

  vector_delete(&vector, NULL);

  return 0;
}
