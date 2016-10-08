#ifndef INCLUDE_BINARYTREEUNIQUE_HPP_
#define INCLUDE_BINARYTREEUNIQUE_HPP_

#include <memory>
#include <string>

class BinaryTreeUniqueNode;
using p_node_t = std::unique_ptr<BinaryTreeUniqueNode>;

class BinaryTreeUniqueNode {
public:
  int data;
  p_node_t left;
  p_node_t right;

  BinaryTreeUniqueNode(int v) : data(v), left(nullptr), right(nullptr) {}
};

namespace BinaryTreeUnique {
  p_node_t create(const std::string& tree);
  std::string toString(const p_node_t& root);
  bool equal(const p_node_t& t1, const p_node_t& t2);
}

#endif  // INCLUDE_BINARYTREEUNIQUE_HPP_
