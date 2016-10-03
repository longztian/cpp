#include "catch.hpp"
#include "LinkedList.hpp"

namespace LL = LinkedList;

TEST_CASE("create", "[LinkedList]") {
  p_node_t head = LL::create({});
  REQUIRE(head == nullptr);

  head = LL::create({1,2,3});
  REQUIRE(head->data == 1);
  REQUIRE(head->next->data == 2);
  REQUIRE(head->next->next->data == 3);
  REQUIRE(head->next->next->next == nullptr);
}

TEST_CASE("toVector", "[LinkedList]") {
  REQUIRE(LL::toVector(nullptr).empty());

  p_node_t head = LL::create({1,2,3});
  REQUIRE(LL::toVector(head) == std::vector<int>({1,2,3}));
}

TEST_CASE("equal", "[LinkedList]") {
  REQUIRE(LL::equal(nullptr, nullptr) == true);
  REQUIRE(LL::equal(LL::create({1}), nullptr) == false);
  REQUIRE(LL::equal(nullptr, LL::create({1})) == false);

  REQUIRE(LL::equal(LL::create({1}), LL::create({1})) == true);
  REQUIRE(LL::equal(LL::create({1,2,3}), LL::create({1,2,3})) == true);
  REQUIRE(LL::equal(LL::create({1,2,3}), LL::create({1,2})) == false);
  REQUIRE(LL::equal(LL::create({1,2,3}), LL::create({1,2,4})) == false);
}
