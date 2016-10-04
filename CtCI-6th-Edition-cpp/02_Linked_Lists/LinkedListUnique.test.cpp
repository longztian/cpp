#include "catch.hpp"
#include "LinkedListUnique.hpp"

namespace LL = LinkedListUnique;

TEST_CASE("linked list with unique pointer: create", "[LinkedListUnique]") {
  auto head = LL::create({});
  REQUIRE(head == nullptr);

  head = LL::create({1,2,3});
  REQUIRE(head->data == 1);
  REQUIRE(head->next->data == 2);
  REQUIRE(head->next->next->data == 3);
  REQUIRE(head->next->next->next == nullptr);
}

TEST_CASE("linked list with unique pointer: toVector", "[LinkedListUnique]") {
  REQUIRE(LL::toVector(nullptr).empty());

  auto head = LL::create({1,2,3});
  REQUIRE(LL::toVector(head) == std::vector<int>({1,2,3}));
}

TEST_CASE("linked list with unique pointer: equal", "[LinkedListUnique]") {
  REQUIRE(LL::equal(nullptr, nullptr) == true);
  REQUIRE(LL::equal(LL::create({1}), nullptr) == false);
  REQUIRE(LL::equal(nullptr, LL::create({1})) == false);

  REQUIRE(LL::equal(LL::create({1}), LL::create({1})) == true);
  REQUIRE(LL::equal(LL::create({1,2,3}), LL::create({1,2,3})) == true);
  REQUIRE(LL::equal(LL::create({1,2,3}), LL::create({1,2})) == false);
  REQUIRE(LL::equal(LL::create({1,2,3}), LL::create({1,2,4})) == false);
}
