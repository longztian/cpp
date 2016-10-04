#ifndef MINSTACK_HPP
#define MINSTACK_HPP

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

#endif
