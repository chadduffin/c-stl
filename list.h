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
// LIST container.

#ifndef __LIST__
#define __LIST__

#include "error.h"
#include "generics.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct LIST LIST;
typedef struct LIST_NODE LIST_NODE;

// @name    struct LIST, LIST
// @purpose Provide a container with the ability to add and remove items to and
//          from the beginning and end of the list in constant time.
// @notes   The LIST container is implemented as a doubly-linked list.
// @example
//
//          LIST *list = NULL;
//
//          list_create(&list);
//
//          /* interact with list */
//
//          list_delete(&list, NULL);

struct LIST {
  unsigned int size_;
  LIST_NODE *head_, *tail_;
};

struct LIST_NODE {
  DATA data_;
  LIST_NODE *next_, *prev_;
};

// @name    list_create
// @purpose Allocate memory for a LIST and update the pointer passed to the
//          function.
// @notes   It is the client's responsibility to ensure the list is deleted
//          when it is done with it.

void list_create(LIST **list);

// @name    list_delete
// @purpose Free memory associated with a LIST pointer safely.
// @notes   A function can be passed as the second parameter that will be called
//          on each item in the array before the array is freed.

void list_delete(LIST **list, void (*f)(DATA*));

// @name    list_back
// @purpose Return a pointer to the data at the end of the list.
// @notes   If the list is empty this will cause an error.

DATA* list_back(LIST *list);

// @name    list_clear
// @purpose Remove all of the items from the list.

void list_clear(LIST *list, void (*f)(DATA*));

// @name    list_empty
// @purpose Return a boolean identifying if the list is empty.

bool list_empty(LIST *list);

// @name    list_front
// @purpose Return a pointer to the data at the front of the list.
// @notes   If the list is empty this will cause an error.

DATA* list_front(LIST *list);

// @name    list_handle
// @purpose Call a specified function on each item in the list.

void list_handle(LIST *list, void (*f)(DATA*));

// @name    list_merge
// @purpose Combine two lists into a single list.
// @notes   The left list will have the result of the combination. The right
//          list will be a valid but empty list.

void list_merge(LIST *list_left, LIST *list_right);

// @name    list_pop_back
// @purpose Remove the last item from the list.
// @notes   If the list is empty this will cause an error.

void list_pop_back(LIST *list);

// @name    list_pop_front
// @purpose Remove the first item from the list.
// @notes   If the list is empty this will cause an error.

void list_pop_front(LIST *list);

// @name    list_push_back
// @purpose Add an item to the back of the list.

void list_push_back(LIST *list, DATA data);

// @name    list_push_front
// @purpose Add an item to the front of the list.

void list_push_front(LIST *list, DATA data);

// @name    list_remove
// @purpose Remove an item from the list identified by its data.
// @notes   Only removes the first matching item.

void list_remove(LIST *list, DATA data);

// @name    list_size
// @purpose Return the size of the list.

unsigned int list_size(LIST *list);

#endif // LIST //

