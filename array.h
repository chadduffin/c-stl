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

// This file contains the data structures and function signatures for the ARRAY
// container.

#ifndef __ARRAY__
#define __ARRAY__

#include "error.h"
#include "generics.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct ARRAY ARRAY;

// @name    struct ARRAY, ARRAY
// @purpose Encapsulate a raw C array, provide functions to interact
//          with / handle the array and provide error checking.
// @example
//
//          ARRAY *array = NULL;
//   
//          array_create(&array, 10);
//
//          /* interact with array */
//
//          array_delete(&array, NULL);

struct ARRAY {
  unsigned int size_;
  DATA *data_;
};

// @name    array_create
// @purpose Allocate memory for an ARRAY and update the pointer passed to the
//          function.
// @notes   The default values for the array items are garbage. It is the
//          client's responsibility to ensure the array is deleted when it is
//          done with it.

void array_create(ARRAY **array, unsigned int size);

// @name    array_delete
// @purpose Free memory associated with an ARRAY pointer safely.
// @notes   A function can be passed as the second parameter that will be called
//          on each item in the array before the array is freed.

void array_delete(ARRAY **array, void (*f)(DATA*));

// @name    array_at
// @purpose Return a pointer to the data at a specific index in the array.
// @notes   Synonymous to raw array indexing with [] operators.

DATA* array_at(ARRAY *array, unsigned int index);

// @name    array_back
// @purpose Return a pointer to the data at the back of the array.
// @notes   If the value has not been changed since array initialization it will
//          be garbage.

DATA* array_back(ARRAY *array);

// @name    array_clear
// @purpose Set all of the array data to 0.
// @notes   Uses memset to clear the entire array.

void array_clear(ARRAY *array);

// @name    array_empty
// @purpose Return a boolean identifying if the array is empty.

bool array_empty(ARRAY *array);

// @name    array_fill
// @purpose Set the value of every item in the array to a specific value.

void array_fill(ARRAY *array, DATA data);

// @name    array_front
// @purpose Return a pointer to the data at the front of the array.
// @notes   If the value has not been changed since array initialization it will
//          be garbage.

DATA* array_front(ARRAY *array);

// @name    array_handle
// @purpose Call a specified function on each item in the array.

void array_handle(ARRAY *array, void (*f)(DATA*));

// @name    array_size
// @purpose Return the size of the array.

unsigned int array_size(ARRAY *array);

void array_iterator_create(ITERATOR **iterator, ARRAY *array);

DATA* array_iterator_data(ITERATOR *iterator);
void array_iterator_next(ITERATOR *iterator);
void array_iterator_prev(ITERATOR *iterator);

#endif // ARRAY //

