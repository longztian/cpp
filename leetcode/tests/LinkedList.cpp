#include "LinkedList.hpp"

namespace LinkedList {

Node::Node(int d) : val(d), next(nullptr) {}

bool Node::operator ==(const Node& rhs) const {
  if (this == &rhs) return true;

  bool isEqual = val == rhs.val;

  if (isEqual) {
    isEqual = equal(next, rhs.next);
  }

  return isEqual;
}

bool equal(const Node* list1, const Node* list2) {
  if (list1 == nullptr && list2 == nullptr) return true;
  if (list1 == nullptr || list2 == nullptr) return false;
  return *list1 == *list2;
}

Node* create(std::initializer_list<int> il) {
  Node* head(nullptr);
  auto node = head;

  for (auto i = il.begin(); i != il.end(); ++i) {
    if (node) {
      node->next = new Node(*i);
      node = node->next;
    } else {
      head = new Node(*i);
      node = head;
    }
  }

  return head;
}

std::vector<int> toVector(const Node* head) {
  std::vector<int> ret;

  auto node = head;
  while (node) {
    ret.push_back(node->val);
    node = node->next;
  }

  return ret;
}

}  // namespace LinkedList
