#include "animalQueue.hpp"

void AnimalQueue::enqueue(Animal&& a) {
  myList.emplace_back(a);
}

p_animal_t AnimalQueue::dequeue() {
  if (myList.empty()) return nullptr;

  auto pA = std::make_unique<Animal>(myList.front());
  myList.pop_front();
  return pA;
}

p_animal_t AnimalQueue::dequeue(AnimalType aType) {
  if (myList.empty()) return nullptr;

  auto i = myList.begin();
  for (; i != myList.end(); ++i) {
    if (i->type == aType) break;
  }

  if (i == myList.end()) return nullptr;

  auto pA = std::make_unique<Animal>(*i);
  myList.erase(i);
  return pA;
}

bool AnimalQueue::empty() const noexcept {
  return myList.empty();
}
