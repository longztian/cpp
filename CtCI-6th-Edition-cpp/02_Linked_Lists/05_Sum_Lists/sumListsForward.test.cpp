#include "catch.hpp"
#include "sumListsForward.hpp"

TEST_CASE("sumListsForward test", "[sumListsForward]") {
  auto l1 = LL::create({6, 1, 7});
  auto l2 = LL::create({2, 9, 5});
  auto l3 = LL::create({3, 9, 5});
  auto l4 = LL::create({9, 3, 9, 5});
  REQUIRE(LL::toVector(sumListsForward(l1, l2)) == std::vector<int>({9, 1, 2}));
  REQUIRE(LL::toVector(sumListsForward(l1, l3)) == std::vector<int>({1, 0, 1, 2}));
  REQUIRE(LL::toVector(sumListsForward(l1, l4)) == std::vector<int>({1, 0, 0, 1, 2}));
}

