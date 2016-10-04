#include "sumListsForward.hpp"
#include "sumLists.hpp"

void reverseList(p_node_t& head) {
  if (head == nullptr) return;

  auto dummy = LL::create({0});

  auto p = head.release(), pNext = p;
  while (p) {
    pNext = p->next.release();
    p->next.reset(dummy->next.release());
    dummy->next.reset(p);
    p = pNext;
  }

  head.reset(dummy->next.release());
}

p_node_t sumListsForward(p_node_t& l1, p_node_t& l2) {
  reverseList(l1);
  reverseList(l2);
  auto sum = sumLists(l1, l2);
  reverseList(l1);
  reverseList(l2);
  reverseList(sum);
  return sum;
}
