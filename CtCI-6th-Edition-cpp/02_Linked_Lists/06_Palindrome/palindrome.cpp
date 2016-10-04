#include "palindrome.hpp"

p_node_t reverseList(const p_node_t& head) {
  auto reverse = LL::create({0});
  auto p = head.get(), pR = reverse->next.get();

  while (p) {
    pR = reverse->next.release();
    reverse->next = std::make_unique<LL::Node>(p->data);
    reverse->next->next.reset(pR);
    p = p->next.get();
  }

  return p_node_t(reverse->next.release());
}

bool palindrome(const p_node_t& head) {
  if (head == nullptr || head->next == nullptr) return true;

  auto reverse = reverseList(head);
  return LL::equal(head, reverse);
}
