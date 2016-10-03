#include "partition.hpp"

void partition(p_node_t& head, int x) {
  if (head == nullptr || head->next == nullptr) return;

  p_node_t lHead = std::make_unique<LinkedList::Node>(0);
  p_node_t rHead = std::make_unique<LinkedList::Node>(0);
  auto lTail = lHead.get();
  auto rTail = rHead.get();

  auto p = head.release();

  while (p) {
    if (p->data < x) {
      lTail->next.reset(p);
      lTail = p;
    }
    else {
      rTail->next.reset(p);
      rTail = p;
    }
    p = p->next.release();
  }

  lTail->next.reset(rHead->next.release());
  head.reset(lHead->next.release());
}
