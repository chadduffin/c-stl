#ifndef __ERROR__
#define __ERROR__

#include <stdio.h>
#include <stdlib.h>

#define ERROR_ZERO(X)      if (!X) { print_error(__FILE__, __LINE__, "cannot be zero"); }
#define ERROR_NULL(X)      if (!X) { print_error(__FILE__, __LINE__, "invalid pointer"); }
#define ERROR_RANGE(X,Y,Z) if ((X < Y) || (X > Z)) { print_error(__FILE__, __LINE__, "value outside range"); }

void print_error(const char *file, int line, const char *error);

#endif // ERROR //

