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

// This file contains the data structures and function signatures for the DEQUE
// container.

#ifndef __DEQUE__
#define __DEQUE__

#include "error.h"
#include "array.h"
#include "generics.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Default size of each DEQUE segment
#define DEQUE_SEGMENT_SIZE 128

typedef struct DEQUE DEQUE;

// @name    struct DEQUE, DEQUE
// @purpose Encapsulate an ARRAY data structure, provide automatic resizing
//          capabilities, identical functions to interact with / handle the
//          array and to provide error checking.
// @notes   The deque does not necessarily store data contiguously, but can
//          gurantee amortized constant time addition and remove of items
//          from the beginning and end of the container.
// @example
//
//          DEQUE *deque = NULL;
//
//          deque_create(&deque);
//
//          /* interact with deque */
//
//          deque_delete(&deque, NULL);

struct DEQUE {
  unsigned int size_, head_, tail_, length_;
  ARRAY **segments_;
};

// @name    deque_create
// @purpose Allocate memory for a DEQUE and update the pointer passed to the
//          function. The deque is initialized with a default capacity of 16.
//          When resizing, the deque will grow its capacity by double.
// @notes   The default size of the deque and the resize relation can both be
//          safely changed by updated the macros above. It is the client's
//          responsibility to ensure the deque is deleted when it is done with
//          it.

void deque_create(DEQUE **deque);

// @name    deque_delete
// @purpose Free memory associated with a DEQUE pointer safely.
// @notes   A function can be passed as the second parameter that will be called
//          on each item in the deque before the deque is freed.

void deque_delete(DEQUE **deque, void(*f)(DATA*));

// @name    deque_at
// @purpose Return a pointer to the data at a specific index in the array.
// @notes   Synonymous to raw array indexing with [] operators.

DATA* deque_at(DEQUE *deque, unsigned int index);

// @name    deque_back
// @purpose Return a pointer to the data at the back of the deque.
// @notes   If the deque is empty this will cause an error.

DATA* deque_back(DEQUE *deque);

// @name    deque_capacity
// @purpose Return the capacity of the deque.

unsigned int deque_capacity(DEQUE *deque);

// @name    deque_clear
// @purpose Remove all of the items from the deque and set the size to zero.
// @notes   The deque does not decrease in capacity.

void deque_clear(DEQUE *deque);

// @name    deque_empty
// @purpose Return a boolean identifying if the deque is empty.

bool deque_empty(DEQUE *deque);

// @name    deque_erase
// @purpose Remove an item from the deque at a specific index. All subsequent
//          items are shifted left by one.

void deque_erase(DEQUE *deque, unsigned int index);

// @name    deque_front
// @purpose Return a pointer to the data at the front of the deque.
// @notes   If the deque is empty this will cause an error.

DATA* deque_front(DEQUE *deque);

// @name    deque_handle
// @purpose Call a specified function on each item in the array.

void deque_handle(DEQUE *deque, void(*f)(DATA*));

// @name    deque_insert
// @purpose Insert an item into a specific index of the deque.
// @notes   This function will cause an error if the index is not between 0 and
//          the size of the deque inclusive,

void deque_insert(DEQUE *deque, DATA data, unsigned int index);

// @name    deque_pop_back
// @purpose Remove the last item from the deque.
// @notes   If the deque is empty this will cause an error.

void deque_pop_back(DEQUE *deque);

// @name    deque_pop_back
// @purpose Remove the last item from the deque.
// @notes   If the deque is empty this will cause an error.

void deque_pop_front(DEQUE *deque);

// @name    deque_push_back
// @purpose Add an item to the end of the deque.

void deque_push_back(DEQUE *deque, DATA data);

// @name    deque_push_back
// @purpose Add an item to the end of the deque.

void deque_push_front(DEQUE *deque, DATA data);

// @name    deque_resize
// @purpose Change the number of items in the deque.
// @notes   If the new size is smaller than the previous size, the last n
//          elements are removed and the capacity of the deque is adjusted. If
//          the new size is larger then n garbage elements are appended to the
//          deque.

void deque_resize(DEQUE *deque, unsigned int size);

// @name    deque_size
// @purpose Return the size of the deque.

unsigned int deque_size(DEQUE *deque);

#endif // DEQUE //

