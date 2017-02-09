#include "getNext.hpp"

DoubleBinaryTreeNode* getNext(const p_node_t& node) {
  if (node == nullptr) return nullptr;

  if (node->right == nullptr) return node->parent;

  // find left most of the right subtree
  auto p = node->right.get();
  while (p->left != nullptr) p = p->left.get();

  return p;
}
