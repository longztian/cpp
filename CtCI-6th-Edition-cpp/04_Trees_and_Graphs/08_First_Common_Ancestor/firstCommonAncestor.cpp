#include <vector>
#include "firstCommonAncestor.hpp"

p_node_t traverse(const p_node_t& root, const p_node_t& node, std::vector<int>& move, int depth) {
  if (root == nullptr) return nullptr;

  if (move.size() == static_cast<size_t>(depth)) move.push_back(0);
  if (root == node) return node;

  auto p = traverse(root->left, node, move, depth+1);
  if (p == node) {
    move[depth] = -1;
    return node;
  }

  p = traverse(root->right, node, move, depth+1);
  if (p == node) {
    move[depth] = 1;
    return node;
  }

  return nullptr;
}

p_node_t firstCommonAncestor(const p_node_t& root, const p_node_t& n1, const p_node_t& n2) {
  if (root == nullptr || n1 == nullptr || n2 == nullptr) return nullptr;
  if (n1 == n2) return n1;

  std::vector<int> move1;
  auto p = traverse(root, n1, move1, 0);
  if (p == nullptr) return nullptr;
  if (move1.empty()) return root;

  std::vector<int> move2;
  p = traverse(root, n2, move2, 0);
  if (p == nullptr) return nullptr;
  if (move2.empty()) return root;

  p = root;
  for (auto i1 = move1.begin(), i2 = move2.begin(); *i1 == *i2; ++i1, ++i2) {
    if (*i1 == 0 || *i2 == 0) return p;

    p = (*i1 == -1 ? p->left : p->right);
  }

  return p;
}
