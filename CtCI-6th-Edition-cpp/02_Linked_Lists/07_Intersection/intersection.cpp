#include <vector>
#include "intersection.hpp"

p_node_t intersection(p_node_t head1, p_node_t head2) {
  if (head1 == nullptr || head2 == nullptr) return nullptr;
  if (head1 == head2) return head1;

  // check if has intersection
  auto p1 = head1, p2 = head2;
  auto n1 = 0, n2 = 0;
  while (p1->next) {
    p1 = p1->next;
    n1 += 1;
  }
  while (p2->next) {
    p2 = p2->next;
    n2 += 1;
  }

  if (p1 != p2) return nullptr;

  // find intersection node
  p1 = head1;
  p2 = head2;
  while (n1 > n2) {
    p1 = p1->next;
    n1 -= 1;
  }
  while (n1 < n2) {
    p2 = p2->next;
    n2 -= 1;
  }

  while (p1 != p2) {
    p1 = p1->next;
    p2 = p2->next;
  }

  return p1;
}
