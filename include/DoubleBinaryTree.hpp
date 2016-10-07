#ifndef DOUBLEBINARYTREE_HPP
#define DOUBLEBINARYTREE_HPP

#include <memory>
#include <string>

class DoubleBinaryTreeNode;
using p_node_t = std::shared_ptr<DoubleBinaryTreeNode>;

class DoubleBinaryTreeNode {
public:
  int data;
  p_node_t parent;
  p_node_t left;
  p_node_t right;

  DoubleBinaryTreeNode(int v) : data(v), parent(nullptr), left(nullptr), right(nullptr) {}
};

namespace DoubleBinaryTree {
  p_node_t create(const std::string& tree);
  std::string toString(const p_node_t& root);
  bool equal(const p_node_t& t1, const p_node_t& t2);
}

#endif
