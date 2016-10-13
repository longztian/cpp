#include "catch.hpp"
#include "sumLists.hpp"

TEST_CASE("sumLists test", "[sumLists]") {
  auto l1 = LL::create({7, 1, 6});
  auto l2 = LL::create({5, 9, 2});
  auto l3 = LL::create({5, 9, 3});
  auto l4 = LL::create({5, 9, 3, 9});
  REQUIRE(LL::toVector(sumLists(l1, l2)) == std::vector<int>({2, 1, 9}));
  REQUIRE(LL::toVector(sumLists(l1, l3)) == std::vector<int>({2, 1, 0, 1}));
  REQUIRE(LL::toVector(sumLists(l1, l4)) == std::vector<int>({2, 1, 0, 0, 1}));
}

