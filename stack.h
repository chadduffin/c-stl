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

// This file contains the data structures and function signatures for the STACK
// container.

#ifndef __STACK__
#define __STACK__

#include "error.h"
#include "vector.h"
#include "generics.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct STACK STACK;

// @name    struct STACK, STACK
// @purpose Encapsulate a VECTOR data structure to provide additional functions
//          that are necessary to create and interact with a stack.
// @example
//
//          STACK *stack = NULL;
//
//          stack_create(&stack);
//
//          /* interact with stack */
//
//          stack_delete(&stack, NULL);

struct STACK {
  VECTOR *vector_;
};

// @name    stack_create
// @purpose Allocate memory for a STACK and update the pointer passed to the
//          function.
// @notes   The stack relies on an underlying VECTOR and acts more like a
//          wrapper than a custom container. It is the client's responsibility
//          to ensure the stack is deleted when it is done with it.

void stack_create(STACK **stack);

// @name    stack_delete
// @purpose Free memory associated with a STACK pointer safely.

void stack_delete(STACK **stack);

// @name    stack_empty
// @purpose Return a boolean identifying if the stack is empty.

bool stack_empty(STACK *stack);

// @name    stack_push
// @purpose Add an item to the top of the stack.

void stack_push(STACK *stack, DATA data);

// @name    stack_pop
// @purpose Remove the top item from the stack.
// @notes   If the stack is empty this will cause an error.

void stack_pop(STACK *stack);

// @name    stack_size
// @purpose Return the size of the stack.

unsigned int stack_size(STACK *stack);

// @name    stack_top
// @purpose Return a pointer to the data at the top of the stack.
// @notes   If the stack is empty this will cause an error.

DATA* stack_top(STACK *stack);

#endif // STACK //

