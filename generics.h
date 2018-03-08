#ifndef __GENERICS__
#define __GENERICS__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "error.h"

typedef union DATA DATA;
typedef struct ITERATOR ITERATOR;

union DATA {
  int my_int;
};

struct ITERATOR {
  void *container_;
  void (*next_)(ITERATOR*), (*prev_)(ITERATOR*);
  DATA* (*data_)(ITERATOR*);

  union {
    void *void_;
    unsigned int uint_;
  };
};

void  iterator_delete(ITERATOR **iterator);

DATA* iterator_data(ITERATOR *iterator);
void  iterator_next(ITERATOR *iterator);
void  iterator_prev(ITERATOR *iterator);

#endif // GENERICS //

