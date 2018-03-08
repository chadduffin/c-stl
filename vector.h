#ifndef __VECTOR__
#define __VECTOR__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "array.h"
#include "error.h"
#include "generics.h"

#define VECTOR_INIT_SIZE       2
#define VECTOR_RESIZE_RELATION 2

typedef struct VECTOR VECTOR;

struct VECTOR {
  unsigned int size_;
  ARRAY *array_;
};

void         vector_create    (VECTOR **vector);
void         vector_delete    (VECTOR **vector, void (*f)(DATA*));

DATA*        vector_at        (VECTOR *vector, unsigned int index);
DATA*        vector_back      (VECTOR *vector);
unsigned int vector_capacity  (VECTOR *vector);
void         vector_clear     (VECTOR *vector);
bool         vector_empty     (VECTOR *vector);
void         vector_erase     (VECTOR *vector, unsigned int index);
DATA*        vector_front     (VECTOR *vector);
void         vector_handle    (VECTOR *vector, void (*f)(DATA*));
void         vector_insert    (VECTOR *vector, DATA data, unsigned int index);
void         vector_pop_back  (VECTOR *vector);
void         vector_push_back (VECTOR *vector, DATA data);
void         vector_resize    (VECTOR *vector, unsigned int size);
unsigned int vector_size      (VECTOR *vector);

#endif // VECTOR //

