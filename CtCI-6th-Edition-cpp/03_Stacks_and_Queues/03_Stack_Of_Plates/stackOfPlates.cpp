#include "stackOfPlates.hpp"

static const int SIZE = 3;

void SetOfStacks::push(int v) {
  if (myStacks.empty() || myStacks.back().size() == SIZE) {
    myStacks.emplace_back(std::vector<int>());
  }

  myStacks.back().emplace_back(v);
}

int SetOfStacks::pop() {
  if (!myStacks.empty()) {
    auto v = myStacks.back().back();
    if (myStacks.back().size() == 1) {
      myStacks.pop_back();
    } else {
      myStacks.back().pop_back();
    }
    return v;
  }
}

int SetOfStacks::popAt(int index) {
  if (index >= 0 && index < myStacks.size()) {
    auto v = myStacks[index].back();
    if (myStacks[index].size() == 1) {
      myStacks.erase(myStacks.cbegin() + index);
    } else {
      myStacks[index].pop_back();
    }
    return v;
  }
}

int SetOfStacks::peek() const {
  if (!myStacks.empty()) {
    return myStacks.back().back();
  }
}

bool SetOfStacks::empty() const noexcept {
  return myStacks.empty();
}

SetOfStacks stackOfPlates() {
  return SetOfStacks();
}
