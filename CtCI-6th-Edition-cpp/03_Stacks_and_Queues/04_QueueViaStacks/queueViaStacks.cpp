#include "queueViaStacks.hpp"

void StacksQueue::push(int v) {
  myBack.push(v);
}

int StacksQueue::pop() {
  if (myFront.empty()) {
    while (!myBack.empty()) {
      myFront.push(myBack.top());
      myBack.pop();
    }
  }
  if (!myFront.empty()) {
    auto v = myFront.top();
    myFront.pop();
    return v;
  }

  return -1;
}

int StacksQueue::peek() const {
  if (myFront.empty()) {
    while (!myBack.empty()) {
      myFront.push(myBack.top());
      myBack.pop();
    }
  }
  if (!myFront.empty()) {
    return myFront.top();
  }

  return -1;
}

bool StacksQueue::empty() const noexcept {
  return myFront.empty() && myBack.empty();
}

StacksQueue queueViaStacks() {
  return StacksQueue();
}
