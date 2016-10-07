#include "minimalTree.hpp"

p_node_t createMinimalTree(const int* begin, const int* end) {
  int n = end - begin;
  if (n <= 0) return nullptr;
  if (n == 1) return std::make_unique<BinaryTreeNode>(*begin);

  auto middle = begin + n / 2;
  auto p = std::make_unique<BinaryTreeNode>(*middle);
  p->left = createMinimalTree(begin, middle);
  p->right = createMinimalTree(middle+1, end);

  return p;
}

p_node_t minimalTree(const std::vector<int>& numbers) {
  if (numbers.empty()) {
    return nullptr;
  }

  return createMinimalTree(numbers.data(), numbers.data() + numbers.size());
}
