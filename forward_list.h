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
// FORWARD_LIST container.

#ifndef __FORWARD_LIST__
#define __FORWARD_LIST__

#include "error.h"
#include "generics.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct FORWARD_LIST FORWARD_LIST;
typedef struct FORWARD_LIST_NODE FORWARD_LIST_NODE;

// @name    struct FORWARD_LIST, FORWARD_LIST
// @purpose Provide a container with the ability to add and remove items to and
//          from the end of the list in constant time.
// @notes   The FORWARD_LIST container is implemented as a singly-linked list.
// @example
//
//          FORWARD_LIST *list = NULL;
//
//          forward_list_create(&list);
//
//          /* interact with list */
//
//          forward_list_delete(&list, NULL);

struct FORWARD_LIST {
  FORWARD_LIST_NODE *head_;
};

struct FORWARD_LIST_NODE {
  DATA data_;
  FORWARD_LIST_NODE *next_;
};

// @name    forward_list_create
// @purpose Allocate memory for a FORWARD_LIST and update the pointer passed to
//          the function.
// @notes   It is the client's responsibility to ensure the list is deleted
//          when it is done with it.

void forward_list_create(FORWARD_LIST **forward_list);

// @name    forward_list_delete
// @purpose Free memory associated with a FORWARD_LIST pointer safely.
// @notes   A function can be passed as the second parameter that will be called
//          on each item in the array before the array is freed.

void forward_list_delete(FORWARD_LIST **forward_list,
                         void (*f)(DATA*));

// @name    forward_list_clear
// @purpose Remove all of the items from the list.

void forward_list_clear(FORWARD_LIST *forward_list,
                        void (*f)(DATA*));

// @name    forward_list_empty
// @purpose Return a boolean identifying if the list is empty.

bool forward_list_empty(FORWARD_LIST *forward_list);

// @name    forward_list_front
// @purpose Return a pointer to the data at the front of the list.
// @notes   If the list is empty this will cause an error.

DATA* forward_list_front(FORWARD_LIST *forward_list);

// @name    forward_list_handle
// @purpose Call a specified function on each item in the list.

void forward_list_handle(FORWARD_LIST *forward_list,
                         void (*f)(DATA*));

// @name    forward_list_merge
// @purpose Combine two lists into a single list.
// @notes   The left list will have the result of the combination. The right
//          list will be a valid but empty list.

void forward_list_merge(FORWARD_LIST *forward_list_left,
                        FORWARD_LIST *forward_list_right);

// @name    forward_list_pop_front
// @purpose Remove the first item fron the list.
// @notes   If the list is empty this will cause an error.

void forward_list_pop_front(FORWARD_LIST *forward_list);

// @name    forward_list_push_front
// @purpose Add an item to the front of the list.

void forward_list_push_front(FORWARD_LIST *forward_list, DATA data);

// @name    forward_list_remove
// @purpose Remove an item from the list identified by its data.
// @notes   Only removes the first matching item.

void forward_list_remove(FORWARD_LIST *forward_list, DATA data);

#endif // FORWARD_LIST //

