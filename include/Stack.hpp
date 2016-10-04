#ifndef STACK_HPP
#define STACK_HPP

#include "LinkedListUnique.hpp"

namespace LL = LinkedListUnique;

class Stack {
public:
  Stack() : myData(LL::Node(0)) {}

  void push(int v) {
    auto pNode = std::make_unique<LL::Node>(v);
    pNode->next.reset(myData.next.release());
    myData.next.reset(pNode.release());
  }

  int pop() {
    if (myData.next) {
      auto pNode = myData.next.release();
      myData.next.reset(pNode->next.release());
      return pNode->data;
    }
    throw "stack is empty";
  }

  int peek() {
    if (myData.next) {
      return myData.next->data;
    }
    throw "stack is empty";
  }

  bool empty() {
    return myData.next == nullptr;
  }

private:
  LL::Node myData;
};

#endif
