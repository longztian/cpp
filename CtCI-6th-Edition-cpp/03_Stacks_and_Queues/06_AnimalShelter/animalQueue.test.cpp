#include "catch.hpp"
#include "animalQueue.hpp"

TEST_CASE("animalQueue test", "[animalQueue]") {
  AnimalQueue q;

  REQUIRE(q.empty() == true);
  q.enqueue(Animal{AnimalType::DOG, 1});
  q.enqueue(Animal{AnimalType::CAT, 2});
  q.enqueue(Animal{AnimalType::DOG, 3});
  q.enqueue(Animal{AnimalType::CAT, 4});
  q.enqueue(Animal{AnimalType::DOG, 5});
  q.enqueue(Animal{AnimalType::CAT, 6});
  REQUIRE(q.empty() == false);

  auto pA = q.dequeue();
  REQUIRE(pA->type == AnimalType::DOG);
  REQUIRE(pA->data == 1);

  pA = q.dequeue();
  REQUIRE(pA->type == AnimalType::CAT);
  REQUIRE(pA->data == 2);

  pA = q.dequeue(AnimalType::DOG);
  REQUIRE(pA->type == AnimalType::DOG);
  REQUIRE(pA->data == 3);

  pA = q.dequeue(AnimalType::DOG);
  REQUIRE(pA->type == AnimalType::DOG);
  REQUIRE(pA->data == 5);

  REQUIRE(q.dequeue(AnimalType::DOG) == nullptr);
  REQUIRE(q.empty() == false);

  pA = q.dequeue(AnimalType::CAT);
  REQUIRE(pA->type == AnimalType::CAT);
  REQUIRE(pA->data == 4);

  pA = q.dequeue(AnimalType::CAT);
  REQUIRE(pA->type == AnimalType::CAT);
  REQUIRE(pA->data == 6);

  REQUIRE(q.dequeue(AnimalType::CAT) == nullptr);
  REQUIRE(q.empty() == true);
}
