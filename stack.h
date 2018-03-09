#ifndef __STACK__
#define __STACK__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "error.h"
#include "vector.h"
#include "generics.h"

typedef struct STACK STACK;

struct STACK {
  VECTOR *vector_;
};

void         stack_create (STACK **stack);
void         stack_delete (STACK **stack);

bool         stack_empty  (STACK *stack);
void         stack_push   (STACK *stack, DATA data);
void         stack_pop    (STACK *stack);
unsigned int stack_size   (STACK *stack);
DATA*        stack_top    (STACK *stack);

#endif // STACK //

