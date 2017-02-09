#include "minStack.hpp"

void MinStack::push(int v) {
  if (myData.empty()) {
    myData.emplace_back(MinStack::Node({v, v}));
  } else {
    auto min = myData.back().min;
    myData.emplace_back(MinStack::Node({v, min < v ? min : v}));
  }
}

int MinStack::pop() {
  if (!myData.empty()) {
    auto v = myData.back().data;
    myData.pop_back();
    return v;
  }

  return -1;
}

int MinStack::peek() const {
  if (!myData.empty()) {
    return myData.back().data;
  }

  return -1;
}

bool MinStack::empty() const noexcept {
  return myData.empty();
}

int MinStack::min() const {
  if (!myData.empty()) {
    return myData.back().min;
  }

  return -1;
}

MinStack minStack() {
  return MinStack();
}
