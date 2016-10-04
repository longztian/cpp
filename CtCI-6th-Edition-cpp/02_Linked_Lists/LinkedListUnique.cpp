#include "LinkedListUnique.hpp"

namespace LinkedListUnique {
  Node::Node(int d) : data(d), next(nullptr) {}

  bool Node::operator ==(const Node& rhs) const {
    if (this == &rhs) return true;

    bool isEqual = data == rhs.data;

    if (isEqual) {
      isEqual = LinkedListUnique::equal(next, rhs.next);
    }

    return isEqual;
  }

  bool equal(const p_node_t& list1, const p_node_t& list2) {
    if (list1 == nullptr && list2 == nullptr) return true;
    if (list1 == nullptr || list2 == nullptr) return false;
    return *list1 == *list2;
  }

  p_node_t create(std::initializer_list<int> il) {
    p_node_t head(nullptr);
    auto node = head.get();

    for (auto i = il.begin(); i != il.end(); ++i) {
      if (node) {
        node->next = std::make_unique<LinkedListUnique::Node>(*i);
        node = node->next.get();
      }
      else {
        head = std::make_unique<LinkedListUnique::Node>(*i);
        node = head.get();
      }
    }

    return head;
  }

  std::vector<int> toVector(const p_node_t& head) {
    std::vector<int> ret;

    auto node = head.get();
    while (node) {
      ret.push_back(node->data);
      node = node->next.get();
    }

    return ret;
  }
}
