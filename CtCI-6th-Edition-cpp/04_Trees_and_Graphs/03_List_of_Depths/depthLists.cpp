#include "depthLists.hpp"

void fillLists(const p_node_t& tree, list_vector_t& lists, int depth) {
  if (tree == nullptr) return;

  if (lists.size() == depth) {
    lists.emplace_back(std::list<int>({tree->data}));
  }
  else {
    lists[depth].push_back(tree->data);
  }

  fillLists(tree->left, lists, depth + 1);
  fillLists(tree->right, lists, depth + 1);
}

list_vector_t depthLists(const p_node_t& tree) {
  list_vector_t lists;

  fillLists(tree, lists, 0);

  return lists;
}
