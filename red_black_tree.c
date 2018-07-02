#include "red_black_tree.h"

RED_BLACK_TREE_NODE NIL = { .color_ = 'b', .left_ = &NIL, .right_ = &NIL, .parent_ = &NIL };

void red_black_tree_create(RED_BLACK_TREE **red_black_tree,
                           bool (*cmp)(KEY*, KEY*)) {
  ERROR_NULL(red_black_tree);

  *red_black_tree = (RED_BLACK_TREE*)(malloc(sizeof(RED_BLACK_TREE)));

  (*red_black_tree)->cmp_ = cmp;
  (*red_black_tree)->size_ = 0;
  (*red_black_tree)->root_ = &NIL;
}

void red_black_tree_delete(RED_BLACK_TREE **red_black_tree) {
  ERROR_NULL(red_black_tree);
  ERROR_NULL(*red_black_tree);

  red_black_tree_clear(*red_black_tree);

  free(*red_black_tree);

  *red_black_tree = NULL;
}

void red_black_tree_clear(RED_BLACK_TREE *red_black_tree) {
  ERROR_NULL(red_black_tree);

  while (red_black_tree->root_ != &NIL) {
    red_black_tree_erase(red_black_tree, red_black_tree->root_->key_);
  }
}

bool red_black_tree_empty(RED_BLACK_TREE *red_black_tree) {
  ERROR_NULL(red_black_tree);

  return !red_black_tree->size_;
}

void red_black_tree_erase(RED_BLACK_TREE *red_black_tree, KEY key) {
  ERROR_NULL(red_black_tree);

  RED_BLACK_TREE_NODE *node = red_black_tree_find(red_black_tree, key);

  if (node == &NIL) {
    return;
  }

  char original_color = node->color_;
  RED_BLACK_TREE_NODE *tmp = node;
  RED_BLACK_TREE_NODE *child = NULL;
  
  if (node->left_ == &NIL) {
    child = node->right_;
    red_black_tree_transplant(red_black_tree, node, node->right_);
  } else if (node->right_ == &NIL) {
    child = node->left_;
    red_black_tree_transplant(red_black_tree, node, node->left_);
  } else {
    tmp = red_black_tree_minimum(node->right_);
    original_color = tmp->color_;
    child = tmp->right_;

    if (tmp->parent_ == node) {
      child->parent_ = tmp;
    } else {
      red_black_tree_transplant(red_black_tree, tmp, tmp->right_);
      tmp->right_ = node->right_;
      tmp->right_->parent_ = tmp;
    }

    red_black_tree_transplant(red_black_tree, node, tmp);
    tmp->left_ = node->left_;
    tmp->left_->parent_ = tmp;
    tmp->color_ = node->color_;
  }

  if (original_color == 'b') {
    red_black_tree_erase_fixup(red_black_tree, child);
  }

  red_black_tree->size_ -= 1;
}

void red_black_tree_erase_fixup(RED_BLACK_TREE *red_black_tree, RED_BLACK_TREE_NODE *node) {
  ERROR_NULL(red_black_tree);
  ERROR_NULL(node);

  RED_BLACK_TREE_NODE *parent = red_black_tree_parent(node);
  RED_BLACK_TREE_NODE *sibling = NULL;

  while ((node != red_black_tree->root_) && (node->color_ == 'b')) {
    if (node == parent->left_) {
      sibling = parent->right_;

      if (sibling->color_ == 'r') {
        sibling->color_ = 'b';
        parent->color_ = 'r';
        red_black_tree_rotate_left(red_black_tree, parent);
        sibling = node->parent_->right_;
      }
      
      if ((sibling->left_->color_ == 'b') && (sibling->right_->color_ == 'b')) {
        sibling->color_ = 'r';
        node = node->parent_;
      } else {
        if (sibling->right_->color_ == 'b') {
          sibling->left_->color_ = 'b';
          sibling->color_ = 'r';
          red_black_tree_rotate_right(red_black_tree, sibling);
          sibling = node->parent_->right_;
        }

        sibling->color_ = node->parent_->color_;
        node->parent_->color_ = 'b';
        sibling->right_->color_ = 'b';
        red_black_tree_rotate_left(red_black_tree, node->parent_);
        node = red_black_tree->root_;
      }
    } else if (node == parent->right_) {
      sibling = parent->left_;

      if (sibling->color_ == 'r') {
        sibling->color_ = 'b';
        parent->color_ = 'r';
        red_black_tree_rotate_right(red_black_tree, parent);
        sibling = node->parent_->left_;
      }
      
      if ((sibling->right_->color_ == 'b') && (sibling->left_->color_ == 'b')) {
        sibling->color_ = 'r';
        node = node->parent_;
      } else {
        if (sibling->left_->color_ == 'b') {
          sibling->right_->color_ = 'b';
          sibling->color_ = 'r';
          red_black_tree_rotate_left(red_black_tree, sibling);
          sibling = node->parent_->left_;
        }

        sibling->color_ = node->parent_->color_;
        node->parent_->color_ = 'b';
        sibling->left_->color_ = 'b';
        red_black_tree_rotate_right(red_black_tree, node->parent_);
        node = red_black_tree->root_;
      }
    }
  }

  node->color_ = 'b';
}

RED_BLACK_TREE_NODE* red_black_tree_find(RED_BLACK_TREE *red_black_tree, KEY key) {
  ERROR_NULL(red_black_tree);

  RED_BLACK_TREE_NODE *node = red_black_tree->root_;

  while ((node != &NIL) && (memcmp(&(node->key_), &key, sizeof(KEY)))) {
    if (red_black_tree->cmp_(&(node->key_), &key)) {
      node = node->left_;
    } else {
      node = node->right_;
    }
  }

  return node;
}

void red_black_tree_insert(RED_BLACK_TREE *red_black_tree, KEY key, DATA data) {
  ERROR_NULL(red_black_tree);

  RED_BLACK_TREE_NODE *tmp = (RED_BLACK_TREE_NODE*)
                             (malloc(sizeof(RED_BLACK_TREE_NODE))),
                      *child = red_black_tree->root_,
                      *root = &NIL;
  tmp->color_ = 'r';
  tmp->key_ = key;
  tmp->data_ = data;
  tmp->left_ = &NIL;
  tmp->right_ = &NIL;
  tmp->parent_ = &NIL;

  while (child != &NIL) {
    root = child;

    if (red_black_tree->cmp_(&(child->key_), &(tmp->key_))) {
      child = child->left_;
    } else {
      child = child->right_;
    }
  }

  tmp->parent_ = root;

  if (root == &NIL) {
    red_black_tree->root_ = tmp;
  } else if (red_black_tree->cmp_(&(root->key_), &(tmp->key_))) {
    root->left_ = tmp;
  } else {
    root->right_ = tmp;
  }

  red_black_tree_insert_fixup(red_black_tree, tmp);
  red_black_tree->size_ += 1;
}

void red_black_tree_insert_fixup(RED_BLACK_TREE *red_black_tree, RED_BLACK_TREE_NODE *node) {
  ERROR_NULL(red_black_tree);
  ERROR_NULL(node);

  RED_BLACK_TREE_NODE *parent = NULL;
  RED_BLACK_TREE_NODE *sibling = NULL;
  RED_BLACK_TREE_NODE *grandparent = NULL;

  while ((parent = red_black_tree_parent(node))->color_ == 'r') {
    grandparent = red_black_tree_parent(parent);

    if (parent == grandparent->left_) {
      sibling = grandparent->right_;

      if (sibling->color_ == 'r') {
        parent->color_ = 'b';
        sibling->color_ = 'b';
        grandparent->color_ = 'r';
        node = grandparent;
      } else {
        if (node == parent->right_) {
          node = parent;
          red_black_tree_rotate_left(red_black_tree, node);
        }

        parent->color_ = 'b';
        grandparent->color_ = 'r';
        red_black_tree_rotate_right(red_black_tree, grandparent);
      }
    } else {
      sibling = grandparent->left_;

      if (sibling->color_ == 'r') {
        parent->color_ = 'b';
        sibling->color_ = 'b';
        grandparent->color_ = 'r';
        node = grandparent;
      } else {
        if (node == parent->left_) {
          node = parent;
          red_black_tree_rotate_right(red_black_tree, node);
        }

        parent->color_ = 'b';
        grandparent->color_ = 'r';
        red_black_tree_rotate_left(red_black_tree, grandparent);
      }
    }
  }

  red_black_tree->root_->color_ = 'b';
}

unsigned int red_black_tree_size(RED_BLACK_TREE *red_black_tree) {
  ERROR_NULL(red_black_tree);

  return red_black_tree->size_;
}

void red_black_tree_transplant(RED_BLACK_TREE *red_black_tree, RED_BLACK_TREE_NODE *src, RED_BLACK_TREE_NODE *dst) {
  ERROR_NULL(red_black_tree);
  ERROR_NULL(src);
  ERROR_NULL(dst);

  if (src->parent_ == &NIL) {
    red_black_tree->root_ = dst;
  } else if (src == src->parent_->left_) {
    src->parent_->left_ = dst;
  } else {
    src->parent_->right_ = dst;
  }

  dst->parent_ = src->parent_;
}
void red_black_tree_rotate_left(RED_BLACK_TREE *red_black_tree, RED_BLACK_TREE_NODE *node) {
  ERROR_NULL(red_black_tree);
  ERROR_NULL(node);

  RED_BLACK_TREE_NODE *tmp = node->right_;

  node->right_ = tmp->left_;

  if (tmp->right_ != &NIL) {
    tmp->left_->parent_ = node;
  }

  tmp->parent_ = node->parent_;

  if (node->parent_ == &NIL) {
    red_black_tree->root_ = tmp;
  } else if (node == node->parent_->left_) {
    node->parent_->left_ = tmp;
  } else {
    node->parent_->right_ = tmp;
  }

  tmp->left_ = node;
  node->parent_ = tmp;
}

void red_black_tree_rotate_right(RED_BLACK_TREE *red_black_tree, RED_BLACK_TREE_NODE *node) {
  ERROR_NULL(red_black_tree);
  ERROR_NULL(node);

  RED_BLACK_TREE_NODE *tmp = node->left_;

  node->left_ = tmp->right_;

  if (tmp->left_ != &NIL) {
    tmp->right_->parent_ = node;
  }

  tmp->parent_ = node->parent_;

  if (node->parent_ == &NIL) {
    red_black_tree->root_ = tmp;
  } else if (node == node->parent_->right_) {
    node->parent_->right_ = tmp;
  } else {
    node->parent_->left_ = tmp;
  }

  tmp->right_ = node;
  node->parent_ = tmp;
}

RED_BLACK_TREE_NODE* red_black_tree_parent(RED_BLACK_TREE_NODE *node) {
  ERROR_NULL(node);
  
  return node->parent_;
}

RED_BLACK_TREE_NODE* red_black_tree_grandparent(RED_BLACK_TREE_NODE *node) {
  ERROR_NULL(node);

  return node->parent_->parent_;
}

RED_BLACK_TREE_NODE* red_black_tree_sibling(RED_BLACK_TREE_NODE *node) {
  ERROR_NULL(node);

  if (node->parent_->left_ == node) {
    return node->parent_->right_;
  }

  return node->parent_->left_;
}

RED_BLACK_TREE_NODE* red_black_tree_uncle(RED_BLACK_TREE_NODE *node) {
  ERROR_NULL(node);

  return red_black_tree_sibling(node->parent_);
}

RED_BLACK_TREE_NODE* red_black_tree_minimum(RED_BLACK_TREE_NODE *node) {
  ERROR_NULL(node);

  while (node->left_ != &NIL) {
    node = node->left_;
  }

  return node;
}
