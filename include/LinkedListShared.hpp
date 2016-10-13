#ifndef INCLUDE_LINKEDLISTSHARED_HPP_
#define INCLUDE_LINKEDLISTSHARED_HPP_

#include <initializer_list>
#include <vector>
#include <memory>

namespace LinkedListShared {

class Node;

}

using p_node_t = std::shared_ptr<LinkedListShared::Node>;

namespace LinkedListShared {

class Node {
 public:
  int data;
  p_node_t next;

  explicit Node(int d);
  bool operator ==(const Node& rhs) const;
};

bool equal(const p_node_t& list1, const p_node_t& list2);
p_node_t create(std::initializer_list<int> il);
std::vector<int> toVector(const p_node_t& head);

}  // namespace LinkedListShared

#endif  // INCLUDE_LINKEDLISTSHARED_HPP_
