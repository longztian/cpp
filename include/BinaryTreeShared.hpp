#ifndef BINARYTREESHARED_HPP
#define BINARYTREESHARED_HPP

#include <memory>
#include <string>

class BinaryTreeSharedNode;
using p_node_t = std::shared_ptr<BinaryTreeSharedNode>;

class BinaryTreeSharedNode {
public:
  int data;
  p_node_t left;
  p_node_t right;

  BinaryTreeSharedNode(int v) : data(v), left(nullptr), right(nullptr) {}
};

namespace BinaryTreeShared {
  p_node_t create(const std::string& tree);
  std::string toString(const p_node_t& root);
  bool equal(const p_node_t& t1, const p_node_t& t2);
}

#endif
