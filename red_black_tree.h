#ifndef __RED_BLACK_TREE__
#define __RED_BLACK_TREE__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "error.h"
#include "generics.h"

typedef struct RED_BLACK_TREE RED_BLACK_TREE;
typedef struct RED_BLACK_TREE_NODE RED_BLACK_TREE_NODE;

struct RED_BLACK_TREE {
  bool (*cmp_)(KEY*, KEY*);
  unsigned int size_;
  RED_BLACK_TREE_NODE *root_;
};

struct RED_BLACK_TREE_NODE {
  char color_;
  KEY key_;
  DATA data_;
  RED_BLACK_TREE_NODE *left_, *right_, *parent_;
};

RED_BLACK_TREE_NODE NIL = { .color_ = 'b',
                            .left_ = &NIL,
                            .right_ = &NIL,
                            .parent_ = &NIL };

void red_black_tree_create(RED_BLACK_TREE **red_black_tree,
                           bool (*cmp)(KEY*, KEY*));
void red_black_tree_delete(RED_BLACK_TREE **red_black_tree);

void red_black_tree_clear(RED_BLACK_TREE *red_black_tree);
bool red_black_tree_empty(RED_BLACK_TREE *red_black_tree);
void red_black_tree_erase(RED_BLACK_TREE *red_black_tree, KEY key);
DATA* red_black_tree_find(RED_BLACK_TREE *red_black_tree, KEY key);
void red_black_tree_insert(RED_BLACK_TREE *red_black_tree, KEY key, DATA data);
unsigned int red_black_tree_size(RED_BLACK_TREE *red_black_tree);

void red_black_tree_rotate_left(RED_BLACK_TREE_NODE *node);
void red_black_tree_rotate_right(RED_BLACK_TREE_NODE *node);
RED_BLACK_TREE_NODE* red_black_tree_parent(RED_BLACK_TREE_NODE *node);
RED_BLACK_TREE_NODE* red_black_tree_grandparent(RED_BLACK_TREE_NODE *node);
RED_BLACK_TREE_NODE* red_black_tree_sibling(RED_BLACK_TREE_NODE *node);
RED_BLACK_TREE_NODE* red_black_tree_uncle(RED_BLACK_TREE_NODE *node);

#endif // RED_BLACK_TREE //
