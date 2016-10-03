#include "sumLists.hpp"

p_node_t sumLists(const p_node_t& l1, const p_node_t& l2) {
  if (l1 == nullptr && l2 == nullptr) return p_node_t(nullptr);

  // create result linked list with a dummy head node
  p_node_t sum = std::make_unique<LinkedList::Node>(0);
  auto p = sum.get();

  // sum
  int v;
  auto p1 = l1.get(), p2 = l2.get();
  while (p1 != nullptr || p2 != nullptr) {
    if (p1 == nullptr ) {
      v = p2->data;
      p2 = p2->next.get();
    }
    else if (p2 == nullptr) {
      v = p1->data;
      p1 = p1->next.get();
    }
    else {
      v = p1->data + p2->data;
      p1 = p1->next.get();
      p2 = p2->next.get();
    }
    p->next = std::make_unique<LinkedList::Node>(v);
    p = p->next.get();
  }

  // process sum
  p = sum->next.get();
  while (p->next) {
    p->next->data += p->data / 10;
    p->data %= 10;
    p = p->next.get();
  }
  // last element
  if (p->data > 9) {
    p->next = std::make_unique<LinkedList::Node>(p->data / 10);
    p->data %= 10;
  }

  return p_node_t(sum->next.release());
}
