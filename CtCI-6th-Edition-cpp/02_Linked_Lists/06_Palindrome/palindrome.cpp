#include "palindrome.hpp"

p_node_t reverseList(const p_node_t& head) {
  auto reverse = LinkedList::create({0});
  auto p = head.get(), pR = reverse->next.get();

  while (p) {
    pR = reverse->next.release();
    reverse->next = std::make_unique<LinkedList::Node>(p->data);
    reverse->next->next.reset(pR);
    p = p->next.get();
  }

  return p_node_t(reverse->next.release());
}

bool palindrome(const p_node_t& head) {
  if (head == nullptr || head->next == nullptr) return true;

  auto reverse = reverseList(head);
  return LinkedList::equal(head, reverse);
}
