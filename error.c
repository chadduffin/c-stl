#include "error.h"

void print_error(const char *file, int line, const char *error) {
  fprintf(stderr, "ERROR in %s at line %u: '%s'.\n", file, line, error);

  exit(1);
}

