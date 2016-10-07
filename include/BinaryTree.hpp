#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <memory>
#include <string>

class BinaryTreeNode;
using p_node_t = std::unique_ptr<BinaryTreeNode>;

class BinaryTreeNode {
public:
  int data;
  p_node_t left;
  p_node_t right;

  BinaryTreeNode(int v) : data(v), left(nullptr), right(nullptr) {}
};

namespace BinaryTree {
  p_node_t create(const std::string& tree);
  std::string toString(const p_node_t& root);
  bool equal(const p_node_t& t1, const p_node_t& t2);
}

#endif
