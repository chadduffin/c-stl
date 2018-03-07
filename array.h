#ifndef __ARRAY__
#define __ARRAY__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "error.h"
#include "generics.h"

typedef struct ARRAY ARRAY;

struct ARRAY {
  unsigned int size_;
  
  DATA *data_;
};

void         array_create (ARRAY **array, unsigned int size);
void         array_delete (ARRAY **array, void (*f)(DATA*));

DATA*        array_at     (ARRAY *array, unsigned int index);
DATA*        array_back   (ARRAY *array);
void         array_clear  (ARRAY *array);
bool         array_empty  (ARRAY *array);
void         array_fill   (ARRAY *array, DATA data);
DATA*        array_front  (ARRAY *array);
void         array_handle (ARRAY *array, void (*f)(DATA*));
unsigned int array_size   (ARRAY *array);

#endif // ARRAY //

