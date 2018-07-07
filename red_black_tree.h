// Copyright 2018 Google
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

#ifndef __RED_BLACK_TREE__
#define __RED_BLACK_TREE__

#include "error.h"
#include "generics.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct RED_BLACK_TREE RED_BLACK_TREE;
typedef struct RED_BLACK_TREE_NODE RED_BLACK_TREE_NODE;

struct RED_BLACK_TREE {
  bool (*cmp_)(KEY*, KEY*);
  unsigned int size_;
  RED_BLACK_TREE_NODE *root_;
};

struct RED_BLACK_TREE_NODE {
  char color_;
  DATA data_;
  KEY key_;
  RED_BLACK_TREE_NODE *left_, *right_, *parent_;
};

extern RED_BLACK_TREE_NODE NIL;

void red_black_tree_create(RED_BLACK_TREE **red_black_tree,
                           bool (*cmp)(KEY*, KEY*));
void red_black_tree_delete(RED_BLACK_TREE **red_black_tree);

void red_black_tree_clear(RED_BLACK_TREE_NODE *node);
bool red_black_tree_empty(RED_BLACK_TREE *red_black_tree);
void red_black_tree_erase(RED_BLACK_TREE *red_black_tree, KEY key);
void red_black_tree_erase_(RED_BLACK_TREE *red_black_tree,
                                RED_BLACK_TREE_NODE *node);
RED_BLACK_TREE_NODE* red_black_tree_find(RED_BLACK_TREE *red_black_tree,
                                         KEY key);
void red_black_tree_handle(RED_BLACK_TREE_NODE *node, void (*f)(DATA*));
void red_black_tree_insert(RED_BLACK_TREE *red_black_tree, KEY key, DATA data);
void red_black_tree_insert_(RED_BLACK_TREE *red_black_tree,
                                 RED_BLACK_TREE_NODE *node);
RED_BLACK_TREE_NODE* red_black_tree_minimum(RED_BLACK_TREE_NODE *node);
unsigned int red_black_tree_size(RED_BLACK_TREE *red_black_tree);
void red_black_tree_transplant(RED_BLACK_TREE *red_black_tree,
                               RED_BLACK_TREE_NODE *src,
                               RED_BLACK_TREE_NODE *dst);
void red_black_tree_rotate_left(RED_BLACK_TREE *red_black_tree,
                                RED_BLACK_TREE_NODE *node);
void red_black_tree_rotate_right(RED_BLACK_TREE *red_black_tree,
                                 RED_BLACK_TREE_NODE *node);

#endif // RED_BLACK_TREE //

