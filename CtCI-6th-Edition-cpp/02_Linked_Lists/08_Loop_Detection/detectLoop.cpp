#include "detectLoop.hpp"

p_node_t detectLoop(const p_node_t& head) {
  if (head == nullptr || head->next == nullptr) return nullptr;
  if (head->next == head) return head;

  auto pFast = head->next->next, pSlow = head->next;

  while (pFast != nullptr && pFast->next != nullptr) {
    if (pFast == pSlow) {
      // found loop, start from head again
      pFast = head;
      while (pFast != pSlow) {
        pFast = pFast->next;
        pSlow = pSlow->next;
      }

      return pSlow;
    }

    pSlow = pSlow->next;
    pFast = pFast->next->next;
  }

  return nullptr;
}
