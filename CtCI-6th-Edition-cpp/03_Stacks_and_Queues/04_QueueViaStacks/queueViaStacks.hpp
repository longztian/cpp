#ifndef QUEUEVIASTACKS_HPP
#define QUEUEVIASTACKS_HPP

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

#endif
