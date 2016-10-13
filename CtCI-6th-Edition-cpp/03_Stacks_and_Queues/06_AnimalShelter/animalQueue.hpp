#ifndef CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_06_ANIMALSHELTER_ANIMALQUEUE_HPP_
#define CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_06_ANIMALSHELTER_ANIMALQUEUE_HPP_

#include <list>
#include <memory>

enum AnimalType {
  DOG,
  CAT
};

struct Animal {
  AnimalType type;
  int data;
};

using p_animal_t = std::unique_ptr<Animal>;

class AnimalQueue {
 public:
  void enqueue(Animal&& a);
  p_animal_t dequeue();
  p_animal_t dequeue(AnimalType);
  bool empty() const noexcept;

 private:
  std::list<Animal> myList;
};

#endif  // CTCI_6TH_EDITION_CPP_03_STACKS_AND_QUEUES_06_ANIMALSHELTER_ANIMALQUEUE_HPP_
