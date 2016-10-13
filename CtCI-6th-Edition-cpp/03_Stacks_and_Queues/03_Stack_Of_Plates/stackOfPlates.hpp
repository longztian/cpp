#ifndef CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_03_STACK_OF_PLATES_STACKOFPLATES_HPP_
#define CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_03_STACK_OF_PLATES_STACKOFPLATES_HPP_

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

#endif  // CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_03_STACK_OF_PLATES_STACKOFPLATES_HPP_
