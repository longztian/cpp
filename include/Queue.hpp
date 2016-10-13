#ifndef INCLUDE_QUEUE_HPP_
#define INCLUDE_QUEUE_HPP_

#include "LinkedListUnique.hpp"

namespace LL = LinkedListUnique;

class Queue {
 public:
  Queue() : myData(LL::Node(0)) {
    myEnd = &myData;
  }

  void push(int v) {
    auto pNode = std::make_unique<LL::Node>(v);
    myEnd->next.reset(pNode.release());
    myEnd = myEnd->next.get();
  }

  int pop() {
    if (myData.next) {
      auto pNode = myData.next.release();
      myData.next.reset(pNode->next.release());
      return pNode->data;
    }
    throw "queue is empty";
  }

  int peek() {
    if (myData.next) {
      return myData.next->data;
    }
    throw "queue is empty";
  }

  bool empty() {
    return myData.next == nullptr;
  }

 private:
  LL::Node myData;
  LL::Node* myEnd;
};

#endif  // INCLUDE_QUEUE_HPP_
