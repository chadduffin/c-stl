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

// @name    struct PRIORITY_QUEUE, PRIORITY_QUEUE
// @purpose Encapsulate a VECTOR data structure to provide additional functions
//          that are necessary to create and interact with a priority queue.
// @notes   The functions 'is_less' and 'is_greater' are defined in generics.h.
// @example
//
//          PRIORITY_QUEUE *priority_queue = NULL;
//
//          priority_queue_create(&priority_queue, is_less);
//
//          /* interact with priority queue */
//
//          priority_queue_delete(&priority_queue);

struct PRIORITY_QUEUE {
  bool (*cmp_)(DATA*, DATA*);
  VECTOR *vector_;
};

// @name    priority_queue_create
// @purpose Allocate memory for a PRIORITY_QUEUE and update the pointer passed
//          to the function.
// @notes   Custom comparator functions can be used to determine how the queue
//          prioritizes items. It is the client's responsibility to ensure the
//          stack is deleted when it is done with it.

void priority_queue_create(PRIORITY_QUEUE **priority_queue,
                           bool (*cmp)(DATA*, DATA*));

// @name    priority_queue_delete
// @purpose Free memory associated with a PRIORITY_QUEUE pointer safely.

void priority_queue_delete(PRIORITY_QUEUE **priority_queue);

// @name    priority_queue_empty
// @purpose Return a boolean identifying if the stack is empty.

bool priority_queue_empty(PRIORITY_QUEUE *priority_queue);

// @name    priority_queue_pop
// @purpose Remove the first item from the queue.
// @notes   If the queue is empty this will cause an error.

void priority_queue_pop(PRIORITY_QUEUE *priority_queue);

// @name    priority_queue_push
// @purpose Add an item to the queue.

void priority_queue_push(PRIORITY_QUEUE *priority_queue, DATA data);

// @name    priority_queue_size
// @purpose Return the size of the queue.

unsigned int priority_queue_size(PRIORITY_QUEUE *priority_queue);

// @name    priority_queue_top
// @purpose Return a pointer to the data at the front of the queue.
// @notes   If the queue is empty this will cause an error.

DATA* priority_queue_top(PRIORITY_QUEUE *priority_queue);

#endif // PRIORITY_QUEUE //
