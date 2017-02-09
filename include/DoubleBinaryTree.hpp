#ifndef INCLUDE_DOUBLEBINARYTREE_HPP_
#define INCLUDE_DOUBLEBINARYTREE_HPP_

#include <memory>
#include <string>

class DoubleBinaryTreeNode;
using p_node_t = std::unique_ptr<DoubleBinaryTreeNode>;

class DoubleBinaryTreeNode {
 public:
  int data;
  DoubleBinaryTreeNode* parent;
  p_node_t left;
  p_node_t right;

  explicit DoubleBinaryTreeNode(int v)
  : data(v), parent(nullptr), left(nullptr), right(nullptr) {}
};

namespace DoubleBinaryTree {

p_node_t create(const std::string& tree);
std::string toString(const p_node_t& root);
bool equal(const p_node_t& t1, const p_node_t& t2);

}  // namespace DoubleBinaryTree

#endif  // INCLUDE_DOUBLEBINARYTREE_HPP_
