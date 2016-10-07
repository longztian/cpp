#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include "isBalanced.hpp"

using node_height_map_t = std::unordered_map<const BinaryTreeUniqueNode*, int>;

int getHeight(const p_node_t& root, node_height_map_t& cache) {
  if (root == nullptr) return 0;

  if(cache.find(root.get()) != cache.end()) return cache.at(root.get());

  auto lh = getHeight(root->left, cache);
  auto rh = getHeight(root->right, cache);
  auto h = std::max(lh, rh) + 1;

  cache[root->left.get()] = lh;
  cache[root->right.get()] = rh;
  cache[root.get()] = h;

  return h;
}

bool isBalanced(const p_node_t& root) {
  if (root == nullptr) return true;

  node_height_map_t heightMap;

  return isBalanced(root->left) &&
         isBalanced(root->right) &&
         std::abs(getHeight(root->left, heightMap) - getHeight(root->right, heightMap)) <= 1;
}
