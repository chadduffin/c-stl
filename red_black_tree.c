#include "red_black_tree.h"

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

  
}

void red_black_tree_insert(RED_BLACK_TREE *red_black_tree, KEY key, DATA data) {
  ERROR_NULL(red_black_tree);

  RED_BLACK_TREE_NODE *tmp = (RED_BLACK_TREE_NODE*)
                             (malloc(sizeof(RED_BLACK_TREE_NODE))),
                      *child = red_black_tree->root_,
                      *root = &NIL;

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

  if ((root == red_black_tree->root_) ||
      (red_black_tree->cmp_(&(root->key_), &(tmp->key_)))) {
    root->left_ = tmp;
  } else {
    root->right_ = tmp;
  }
}

void red_black_tree_rotate_left(RED_BLACK_TREE_NODE *node) {
  ERROR_NULL(node);

  RED_BLACK_TREE_NODE *tmp = node->right_;

  if (tmp != &NIL) {
    node->right_ = tmp->left_;
    tmp->left_ = node;

    if (node->right_ != &NIL) {
      node->right_->parent_ = node;
    }

    if (node->parent_->right_ == node) {
      node->parent_->right_ = tmp;
    } else {
      node->parent_->left_ = tmp;
    }

    tmp->parent_ = node->parent_;
    node->parent_ = tmp;
  }
}

void red_black_tree_rotate_right(RED_BLACK_TREE_NODE *node) {
  ERROR_NULL(node);

  RED_BLACK_TREE_NODE *tmp = node->left_;

  if (tmp != &NIL) {
    node->left_ = tmp->right_;
    tmp->right_ = node;

    if (node->left_ != &NIL) {
      node->left_->parent_ = node;
    }

    if (node->parent_->right_ == node) {
      node->parent_->right_ = tmp;
    } else {
      node->parent_->left_ = tmp;
    }

    tmp->parent_ = node->parent_;
    node->parent_ = tmp;
  }

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

