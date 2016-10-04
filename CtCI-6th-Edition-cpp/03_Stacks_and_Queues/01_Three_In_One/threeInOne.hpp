#ifndef THREEINONE_HPP
#define THREEINONE_HPP

#include <memory>

class MyStack {
public:
  MyStack(int* buffer, int size);
  void push(int v);
  int pop();
  int peek();
  bool empty();

private:
  int* myBegin;
  int* myEnd;
  int* myTop;
};

using p_stack_t = std::shared_ptr<MyStack>;

void threeInOne(p_stack_t& s1, p_stack_t& s2, p_stack_t& s3);

#endif
