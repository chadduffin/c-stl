#ifndef __DEQUE__
#define __DEQUE__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "array.h"
#include "error.h"
#include "generics.h"

#define DEQUE_SEGMENT_SIZE 128

typedef struct DEQUE DEQUE;

struct DEQUE {
  unsigned int size_, middle_, segment_count_;
  ARRAY **arrays_;
};

void         deque_create    (DEQUE **deque);
void         deque_delete    (DEQUE **deque, void (*f)(DATA*));

DATA*        deque_at        (DEQUE *deque, unsigned int index);
DATA*        deque_back      (DEQUE *deque);
unsigned int deque_capacity  (DEQUE *deque);
void         deque_clear     (DEQUE *deque);
bool         deque_empty     (DEQUE *deque);
void         deque_erase     (DEQUE *deque, unsigned int index);
DATA*        deque_front     (DEQUE *deque);
void         deque_handle    (DEQUE *deque, void (*f)(DATA*));
void         deque_insert    (DEQUE *deque, DATA data, unsigned int index);
void         deque_pop_back  (DEQUE *deque);
void         deque_push_back (DEQUE *deque, DATA data);
void         deque_resize    (DEQUE *deque, unsigned int size);
unsigned int deque_size      (DEQUE *deque);

#endif // DEQUE //

