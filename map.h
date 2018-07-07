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

#ifndef __MAP__
#define __MAP__

#include "error.h"
#include "generics.h"
#include "red_black_tree.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct MAP MAP;

// @name    struct MAP, MAP
// @purpose Encapsulates a RED_BLACK_TREE data structure to provide a simpler
//          and cleaner interface to interact with.
// @notes   The function 'key_is_less' is defined in generics.h.
// @example
//
//          MAP *map = NULL;
//
//          map_create(&map, &key_is_less);
//
//          /* interact with map */
//
//          map_delete(&map);

struct MAP {
  unsigned int size_;
  RED_BLACK_TREE *red_black_tree_;
};

// @name    map_create
// @purpose Allocate memory for a MAP and update the pointer passed to the
//          function.

void map_create(MAP **map, bool (*cmp)(KEY*, KEY*));

// @name    map_delete
// @purpose Free memory associated with a MAP pointer safely.

void map_delete(MAP **map);

// @name    map_clear
// @purpose Remove all of the items from the map and set the size to zero.

void map_clear(MAP *map);

// @name    map_empty
// @purpose Return a boolean identifying if the stack is empty.

bool map_empty(MAP *map);

// @name    map_erase
// @purpose Remove an item from the map.
// @notes   Removes the first item with a matching key.

void map_erase(MAP *map, KEY key);

// @name    map_find
// @purpose Search the map for an item with a matching key.
// @notes   Returns the DATA associated with the first matched item.

DATA* map_find(MAP *map, KEY key);

// @name    map_handle
// @purpose Call a specified function on the data of each item in the map.

void map_handle(MAP *map, void (*f)(DATA*));

// @name    map_insert
// @purpose Insert an item into the map with the specified KEY and DATA.

void map_insert(MAP *map, KEY key, DATA data);

// @name    map_size
// @purpose Return the size of the map.

unsigned int map_size(MAP *map);

#endif // MAP //

