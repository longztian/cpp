#include "validateBST.hpp"

bool validateBST(const p_node_t& root) {
  if (root == nullptr) return true;

  return (root->left == nullptr ? true : root->data >= root->left->data) &&
         (root->right == nullptr ? true : root->data < root->right->data) &&
         validateBST(root->left) &&
         validateBST(root->right);
}
