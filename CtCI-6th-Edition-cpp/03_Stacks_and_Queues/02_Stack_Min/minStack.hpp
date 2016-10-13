#ifndef CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_02_STACK_MIN_MINSTACK_HPP_
#define CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_02_STACK_MIN_MINSTACK_HPP_

#include <memory>
#include <vector>

class MinStack {
 public:
  void push(int v);
  int pop();
  int peek() const;
  bool empty() const noexcept;
  int min() const;

 private:
  struct Node {
    int data;
    int min;
  };

  std::vector<Node> myData;
};

using p_stack_t = std::unique_ptr<MinStack>;

MinStack minStack();

#endif  // CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_02_STACK_MIN_MINSTACK_HPP_
