#ifndef CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_01_THREE_IN_ONE_THREEINONE_HPP_
#define CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_01_THREE_IN_ONE_THREEINONE_HPP_

#include <memory>

class ThreeInOneStack {
 public:
  ThreeInOneStack(int* buffer, int size);
  void push(int v);
  int pop();
  int peek();
  bool empty();

 private:
  int* myBegin;
  int* myEnd;
  int* myTop;
};

using p_stack_t = std::shared_ptr<ThreeInOneStack>;

void threeInOne(p_stack_t& s1, p_stack_t& s2, p_stack_t& s3);

#endif  // CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_01_THREE_IN_ONE_THREEINONE_HPP_
