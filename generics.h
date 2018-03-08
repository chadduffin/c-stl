#ifndef __GENERICS__
#define __GENERICS__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "error.h"

typedef union KEY KEY;
typedef union DATA DATA;

union KEY {
  int my_int;
};

union DATA {
  int my_int;
};

bool greater(KEY *left, KEY *right);

#endif // GENERICS //

