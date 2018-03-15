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

// This file contains the data structures and function signatures for the VECTOR
// container.

#ifndef __VECTOR__
#define __VECTOR__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "array.h"
#include "error.h"
#include "generics.h"

// Default VECTOR capacity
#define VECTOR_INIT_CAPACITY   16
// Magnitude to increase VECTOR capacity by when resizing
#define VECTOR_RESIZE_RELATION 2

typedef struct VECTOR VECTOR;

// @name    struct VECTOR, VECTOR
// @purpose Encapsulate an ARRAY data structure, provide automatic resizing
//          capabilities, identical functions to interact with / handle the
//          array and to provide error checking.
// @example
//
//          VECTOR *vector = NULL;
//
//          vector_create(&vector);
//
//          /* interact with vector */
//
//          vector_delete(&vector, NULL);

struct VECTOR {
  unsigned int size_;
  ARRAY *array_;
};

// @name    vector_create
// @purpose Allocate memory for a VECTOR and update the pointer passed to the
//          function. The vector is initialized with a default capacity of 16.
//          When resizing, the vector will grow its capacity by double.
// @notes   The default size of the vector and the resize relation can both be
//          safely changed by updated the macros above. It is the client's
//          responsibility to ensure the vector is deleted when it is done with
//          it.

void vector_create(VECTOR **vector);

// @name    vector_delete
// @purpose Free memory associated with a VECTOR pointer safely.
// @notes   A function can be passed as the second parameter that will be called
//          on each item in the vector before the vector is freed.

void vector_delete(VECTOR **vector, void (*f)(DATA*));

// @name    vector_at
// @purpose Return a pointer to the data at a specific index in the array.
// @notes   Synonymous to raw array indexing with [] operators.

DATA* vector_at(VECTOR *vector, unsigned int index);

// @name    vector_back
// @purpose Return a pointer to the data at the back of the vector.
// @notes   If the vector is empty this will cause an error.

DATA* vector_back(VECTOR *vector);

// @name    vector_capacity
// @purpose Return the capacity of the vector.

unsigned int vector_capacity(VECTOR *vector);

// @name    vector_clear
// @purpose Remove all of the items from the vector and set the size to zero.
// @notes   The vector does not decrease in capacity.

void vector_clear(VECTOR *vector);

// @name    vector_empty
// @purpose Return a boolean identifying if the vector is empty.

bool vector_empty(VECTOR *vector);

// @name    vector_erase
// @purpose Remove an item from the vector at a specific index. All subsequent
//          items are shifted left by one.

void vector_erase(VECTOR *vector, unsigned int index);

// @name    vector_front
// @purpose Return a pointer to the data at the front of the vector.
// @notes   If the vector is empty this will cause an error.

DATA* vector_front(VECTOR *vector);

// @name    vector_handle
// @purpose Call a specified function on each item in the array.

void vector_handle(VECTOR *vector, void (*f)(DATA*));

// @name    vector_insert
// @purpose Insert an item into a specific index of the vector.
// @notes   This function will cause an error if the index is not between 0 and
//          the size of the vector inclusive,

void vector_insert(VECTOR *vector, DATA data, unsigned int index);

// @name    vector_pop_back
// @purpose Remove the last item from the vector.
// @notes   If the vector is empty this will cause an error.

void vector_pop_back(VECTOR *vector);

// @name    vector_push_back
// @purpose Add an item to the end of the vector.

void vector_push_back(VECTOR *vector, DATA data);

// @name    vector_resize
// @purpose Change the number of items in the vector.
// @notes   If the new size is smaller than the previous size, the last n
//          elements are effectively removed. If the new size is larger then
//          n garbage elements are appended to the vector.

void vector_resize(VECTOR *vector, unsigned int size);

// @name    vector_size
// @purpose Return the size of the vector.

unsigned int vector_size(VECTOR *vector);

// @name    vector_swap
// @purpose Swap two items of the vector.

void vector_swap(VECTOR *vector, unsigned int first, unsigned int second);

#endif // VECTOR //

