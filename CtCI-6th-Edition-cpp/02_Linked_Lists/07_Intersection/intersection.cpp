#include <vector>
#include "intersection.hpp"

std::vector<const Node*> listToVector(const Node* head) {
  std::vector<const Node*> nodes;
  while (head) {
    nodes.push_back(head);
    head = head->next;
  }

  return nodes;
}

Node* intersection(const Node* head1, const Node* head2) {
  if (head1 == nullptr || head2 == nullptr) return nullptr;

  auto nodes1 = listToVector(head1);
  auto nodes2 = listToVector(head2);

  auto p1 = nodes1.crbegin(), p2 = nodes2.crbegin(), p1e = nodes1.crend(), p2e = nodes2.crend();
  while (p1 != p1e && p2 != p2e) {
    if (p1 != p2) break;
    p1 += 1;
    p2 += 1;
  }

  return p1 == nodes1.crbegin() ? nullptr : (Node*) (*p1);
}
