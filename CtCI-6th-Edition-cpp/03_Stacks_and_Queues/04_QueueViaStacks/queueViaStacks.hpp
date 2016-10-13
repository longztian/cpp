#ifndef CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_04_QUEUEVIASTACKS_QUEUEVIASTACKS_HPP_
#define CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_04_QUEUEVIASTACKS_QUEUEVIASTACKS_HPP_

#include <stack>

class StacksQueue {
 public:
  void push(int v);
  int pop();
  int peek() const;
  bool empty() const noexcept;

 private:
  mutable std::stack<int> myFront;
  mutable std::stack<int> myBack;
};

StacksQueue queueViaStacks();

#endif  // CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_04_QUEUEVIASTACKS_QUEUEVIASTACKS_HPP_
