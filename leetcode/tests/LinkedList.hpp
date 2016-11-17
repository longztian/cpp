#ifndef LEETCODE_TESTS_LINKEDLIST_HPP_
#define LEETCODE_TESTS_LINKEDLIST_HPP_

#include <initializer_list>
#include <vector>

namespace LinkedList {

class Node {
 public:
  int val;
  Node* next;

  explicit Node(int d);
  bool operator ==(const Node& rhs) const;
};

bool equal(const Node* list1, const Node* list2);
Node* create(std::initializer_list<int> il);
std::vector<int> toVector(const Node* head);

}  // namespace LinkedList

#endif  // LEETCODE_TESTS_LINKEDLIST_HPP_
