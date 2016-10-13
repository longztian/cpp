#include "kthToLast.hpp"

const p_node_t& kthToLast(const p_node_t& head, int k) {
  if (head == nullptr || k <= 1) return head;

  auto p = head.get();
  while (p->next && k > 2) {
    p = p->next.get();
    k -= 1;
  }

  return p->next;
}
