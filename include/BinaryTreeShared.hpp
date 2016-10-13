#ifndef INCLUDE_BINARYTREESHARED_HPP_
#define INCLUDE_BINARYTREESHARED_HPP_

#include <memory>
#include <string>

class BinaryTreeSharedNode;
using p_node_t = std::shared_ptr<BinaryTreeSharedNode>;

class BinaryTreeSharedNode {
 public:
  int data;
  p_node_t left;
  p_node_t right;

  explicit BinaryTreeSharedNode(int v)
  : data(v), left(nullptr), right(nullptr) {}
};

namespace BinaryTreeShared {

p_node_t create(const std::string& tree);
std::string toString(const p_node_t& root);
bool equal(const p_node_t& t1, const p_node_t& t2);

}  // namespace BinaryTreeShared

#endif  // INCLUDE_BINARYTREESHARED_HPP_
