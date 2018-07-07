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

#ifndef __QUAD_TREE__
#define __QUAD_TREE__

#include "error.h"
#include "list.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define QUADRANT(X,Y,Z,Q) Q=0; if (X>=Z/2) { X-=Z/2; } else { Q+=1; } \
                               if (Y>=Z/2) { Y-=Z/2; } else { Q+=2; }

typedef struct QUAD_TREE QUAD_TREE;
typedef struct QUAD_TREE_NODE QUAD_TREE_NODE;

struct QUAD_TREE {
  QUAD_TREE_NODE *root_;
};

struct QUAD_TREE_NODE {
  unsigned int size_, count_;

  union {
    LIST *leaves_[4];
    QUAD_TREE_NODE *branches_[4];
  };
};

void quad_tree_create(QUAD_TREE **quad_tree, unsigned int size);
void quad_tree_delete(QUAD_TREE **quad_tree, void (*f)(DATA*));

void quad_tree_clear(QUAD_TREE_NODE *node, void (*f)(DATA*));
LIST* quad_tree_lookup(QUAD_TREE *quad_tree, unsigned int x, unsigned int y);
void quad_tree_insert(QUAD_TREE *quad_tree, DATA data,
                      unsigned int x, unsigned int y);
void quad_tree_insert_at(QUAD_TREE_NODE *node, DATA data,
                         unsigned int x, unsigned int y);
void quad_tree_remove(QUAD_TREE *quad_tree, DATA data,
                      unsigned int x, unsigned int y);
void quad_tree_remove_at(QUAD_TREE_NODE *node, DATA data,
                         unsigned int x, unsigned int y);
void quad_tree_update(QUAD_TREE *quad_tree, DATA data,
                      unsigned int src_x, unsigned int src_y,
                      unsigned int dst_x, unsigned int dst_y);

#endif // QUAD_TREE //

