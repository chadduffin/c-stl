#include "quad_tree.h"

void quad_tree_create(QUAD_TREE **quad_tree, unsigned int size) {
  ERROR_NULL(quad_tree);

  *quad_tree = (QUAD_TREE*)(malloc(sizeof(QUAD_TREE)));

  (*quad_tree)->root_ = (QUAD_TREE_NODE*)(calloc(1, sizeof(QUAD_TREE_NODE)));
  (*quad_tree)->root_->size_ = size;
}

void quad_tree_delete(QUAD_TREE **quad_tree, void (*f)(DATA*)) {
  ERROR_NULL(quad_tree);
  ERROR_NULL(*quad_tree);
  
  quad_tree_clear((*quad_tree)->root_, f);

  free(*quad_tree);

  *quad_tree = NULL;
}

void quad_tree_clear(QUAD_TREE_NODE *node, void (*f)(DATA*)) {
  ERROR_NULL(node);

  for (int i = 0; i < 4; i += 1) {
    if ((node->size_ > 2) && (node->branches_[i])) {
      quad_tree_clear(node->branches_[i], f);
    } else if (node->leaves_[i]) {
      list_delete(&(node->leaves_[i]), f);
    }
  }

  free(node);
}

void quad_tree_insert(QUAD_TREE *quad_tree, DATA data, unsigned int x, unsigned int y) {
  ERROR_NULL(quad_tree);
  ERROR_NULL(quad_tree->root_);

  quad_tree_insert_at(quad_tree->root_, data, x, y);
}

void quad_tree_insert_at(QUAD_TREE_NODE *node, DATA data,
                         unsigned int x, unsigned int y) {
  ERROR_NULL(node);

  unsigned int quadrant = 0;

  while (node->size_ > 2) {
    QUADRANT(x, y, node->size_, quadrant);

    node->count_ += 1;

    if (!node->branches_[quadrant]) {
      node->branches_[quadrant] = (QUAD_TREE_NODE*)(calloc(1, sizeof(QUAD_TREE_NODE)));
      node->branches_[quadrant]->size_ = (node->size_) / 2;
    }

    node = node->branches_[quadrant];
  }

  QUADRANT(x, y, node->size_, quadrant);

  if (!node->leaves_[quadrant]) {
    list_create(&(node->leaves_[quadrant]));
  }

  list_push_back(node->leaves_[quadrant], data);
}

LIST* quad_tree_lookup(QUAD_TREE *quad_tree, unsigned int x, unsigned int y) {
  ERROR_NULL(quad_tree);

  unsigned int quadrant = 0;
  QUAD_TREE_NODE *root = quad_tree->root_;

  while (root->size_ > 2) {
    QUADRANT(x, y, root->size_, quadrant);

    root = root->branches_[quadrant];

    if (!root) { return NULL; }
  }

  QUADRANT(x, y, root->size_, quadrant);

  return root->leaves_[quadrant];
}

void quad_tree_remove(QUAD_TREE *quad_tree, DATA data, unsigned int x, unsigned int y) {
  ERROR_NULL(quad_tree);

  quad_tree_remove_at(quad_tree->root_, data, x, y);
}

void quad_tree_remove_at(QUAD_TREE_NODE *node, DATA data, unsigned int x, unsigned int y) {
  ERROR_NULL(node);

  unsigned int quadrant = 0;

  while (node->size_ > 2) {
    QUADRANT(x, y, node->size_, quadrant);

    node->count_ -= 1;

    if (!node->branches_[quadrant]) {
      return;
    }

    node = node->branches_[quadrant];
  }

  QUADRANT(x, y, node->size_, quadrant);

  if (!node->leaves_[quadrant]) {
    list_remove(node->leaves_[quadrant], data);
  }
}

void quad_tree_update(QUAD_TREE *quad_tree, DATA data, unsigned int src_x, unsigned int src_y, unsigned int dst_x, unsigned int dst_y) {
  ERROR_NULL(quad_tree);

  unsigned int src_quadrant = 0,
               dst_quadrant = 0;
  QUAD_TREE_NODE *root = quad_tree->root_;

  while (root->size_ > 2) {
    QUADRANT(src_x, src_y, root->size_, src_quadrant);
    QUADRANT(dst_x, dst_y, root->size_, dst_quadrant);

    if ((!root->branches_[src_quadrant] || !root->branches_[dst_quadrant]) ||
        (src_quadrant != dst_quadrant)) {
      quad_tree_insert(quad_tree, data, dst_x, dst_y);
      quad_tree_remove(quad_tree, data, src_x, src_y);
      return;
    }

    root = root->branches_[src_quadrant];
  }

  QUADRANT(src_x, src_y, root->size_, src_quadrant);
  QUADRANT(dst_x, dst_y, root->size_, dst_quadrant);

  quad_tree_insert(quad_tree, data, dst_x, dst_y);
  quad_tree_remove(quad_tree, data, src_x, src_y);
}

