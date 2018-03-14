// Copyright 2018 Chad S Duffin
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

// This file contains the data structures and function signatures for the
// PRIORITY_QUEUE container.

#ifndef __PRIORITY_QUEUE__
#define __PRIORITY_QUEUE__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "error.h"
#include "vector.h"
#include "generics.h"

typedef struct PRIORITY_QUEUE PRIORITY_QUEUE;

struct PRIORITY_QUEUE {
  bool (*cmp)(DATA*, DATA*);
  VECTOR *vector_;
};

void priority_queue_create(PRIORITY_QUEUE **priority_queue, bool (*cmp)(DATA*, DATA*));
void priority_queue_delete(PRIORITY_QUEUE **priority_queue);

bool priority_queue_empty(PRIORITY_QUEUE *priority_queue);
void priority_queue_pop(PRIORITY_QUEUE *priority_queue);
void priority_queue_push(PRIORITY_QUEUE *priority_queue);
unsigned int priority_queue_size(PRIORITY_QUEUE *priority_queue);
DATA* priority_queue_top(PRIORITY_QUEUE *priority_queue);

#endif // PRIORITY_QUEUE //
