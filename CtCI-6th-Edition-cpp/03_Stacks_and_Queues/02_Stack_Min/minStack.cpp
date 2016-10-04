#include "minStack.hpp"

void MinStack::push(int v) {
  if (myData.empty()) {
    myData.emplace_back(MinStack::Node({v, v}));
  }
  else {
    auto min = myData.back().min;
    myData.emplace_back(MinStack::Node({v, std::min(min, v)}));
  }
}

int MinStack::pop() {
  if (!myData.empty()) {
    auto v = myData.back().data;
    myData.pop_back();
    return v;
  }
}

int MinStack::peek() const {
  if (!myData.empty()) {
    return myData.back().data;
  }
}

bool MinStack::empty() const noexcept {
  return myData.empty();
}

int MinStack::min() const {
  if (!myData.empty()) {
    return myData.back().min;
  }
}

MinStack minStack() {
  return MinStack();
}
