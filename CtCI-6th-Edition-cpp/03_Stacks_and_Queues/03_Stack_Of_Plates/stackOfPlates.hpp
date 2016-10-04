#ifndef STACKOFPLATES_HPP
#define STACKOFPLATES_HPP

#include <vector>
#include <memory>

class SetOfStacks {
public:
  void push(int v);
  int pop();
  int peek() const;
  bool empty() const noexcept;
  int popAt(int index);

private:
  std::vector<std::vector<int>> myStacks;
};

SetOfStacks stackOfPlates();

#endif
