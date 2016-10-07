#include "getNext.hpp"

p_node_t getNext(const p_node_t& node) {
  if (node == nullptr) return nullptr;

  if (node->right == nullptr) return node->parent;

  // find left most of the right subtree
  p_node_t p = node->right;
  while (p->left != nullptr) p = p->left;

  return p;
}
