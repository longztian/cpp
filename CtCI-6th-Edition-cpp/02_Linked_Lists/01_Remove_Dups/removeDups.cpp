#include <unordered_set>
#include "removeDups.hpp"

bool exist(const LinkedList::Node* begin, const LinkedList::Node* end, int v) {
  for (auto p = begin; p != end; p = p->next.get()) {
    if (p->data == v) return true;
  }

  return end->data == v;
}

void removeDups(p_node_t& head) {
  if (head == nullptr) return;

  // tmp buffer for unique values
  // std::unordered_set<int> values({head->data});
  // auto p = head.get();
  // while (p->next) {
  //   if (values.find(p->next->data) != values.end()) {
  //     // remove next
  //     p->next.reset(p->next->next.release());
  //   }
  //   else {
  //     // new value, insert
  //     values.insert(p->next->data);
  //     p = p->next.get();
  //   }
  // }
  //
  // not use tmp buffer
  auto p = head.get();
  while (p->next) {
    if (exist(head.get(), p, p->next->data)) {
      // duplicate, remove
      p->next.reset(p->next->next.release());
    }
    else {
      p = p->next.get();
    }
  }
}
