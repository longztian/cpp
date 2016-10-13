#include "catch.hpp"
#include "intersection.hpp"

TEST_CASE("no intersection", "[intersection]") {
  REQUIRE(intersection(nullptr, nullptr) == nullptr);
  REQUIRE(intersection(LL::create({1, 2, 3, 4}), LL::create({1, 2, 3, 4})) == nullptr);
}

TEST_CASE("return intersection for sublist", "[intersection]") {
  p_node_t l1 = LL::create({1, 2, 3, 4});
  p_node_t l2 = l1->next->next;
  REQUIRE(intersection(l1, l2) == l2);
  REQUIRE(intersection(l2, l1) == l2);
}

TEST_CASE("return intersection starts from a middle node", "[intersection]") {
  p_node_t l1 = LL::create({1, 2, 3, 4});
  p_node_t l2 = LL::create({5});
  l2->next = l1->next->next;
  REQUIRE(intersection(l1, l2) == l2->next);
  REQUIRE(intersection(l2, l1) == l2->next);
}
