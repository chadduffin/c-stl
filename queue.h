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

// This file contains the data structures and function signatures for the QUEUE
// container.

#ifndef __QUEUE__
#define __QUEUE__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"
#include "error.h"
#include "generics.h"

typedef struct QUEUE QUEUE;

// @name    struct QUEUE, QUEUE
// @purpose Encapsulate a LIST data structure to provide additional functions
//          that are necessary to create and interact with a queue.
// @example
//
//          QUEUE *queue = NULL;
//
//          queue_create(&queue);
//
//          /* interact with queue */
//
//          queue_delete(&queue, NULL);

struct QUEUE {
  LIST *list_;
};

// @name    queue_create
// @purpose Allocate memory for a QUEUE and update the pointer passed to the
//          function.
// @notes   The queue relies on an underlying LIST and acts more like a wrapper
//          than a custom container. It is the client's responsibility to ensure
//          the queue is deleted when it is done with it.

void queue_create(QUEUE **queue);

// @name    queue_delete
// @purpose Free memory associated with a QUEUE pointer safely.

void queue_delete(QUEUE **queue);

// @name    queue_back
// @purpose Return a pointer to the data at the end of the queue.
// @notes   If the queue is empty this will cause an error.

DATA* queue_back(QUEUE *queue);

// @name    queue_empty
// @purpose Return a boolean identifying if the queue is empty.

bool queue_empty(QUEUE *queue);

// @name    queue_front
// @purpose Return a pointer to the data at the beginning of the queue.
// @notes   If the queue is empty this will cause an error.

DATA* queue_front(QUEUE *queue);

// @name    queue_pop
// @purpose Remove the first item from the queue.
// @notes   If the queue is empty this will cause an error.

void queue_pop(QUEUE *queue);

// @name    queue_push
// @purpose Add an item to the end of the queue.

void queue_push(QUEUE *queue, DATA data);

// @name    queue_size
// @purpose Return the size of the queue.

unsigned int queue_size(QUEUE *queue);

#endif // QUEUE //

