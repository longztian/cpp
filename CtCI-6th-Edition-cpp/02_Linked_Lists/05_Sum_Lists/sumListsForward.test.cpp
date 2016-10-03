#include "catch.hpp"
#include "sumListsForward.hpp"

TEST_CASE("sumListsForward test", "[sumListsForward]") {
  auto l1 = LinkedList::create({6,1,7});
  auto l2 = LinkedList::create({2,9,5});
  auto l3 = LinkedList::create({3,9,5});
  auto l4 = LinkedList::create({9,3,9,5});
  REQUIRE(LinkedList::toVector(sumListsForward(l1, l2)) == std::vector<int>({9,1,2}));
  REQUIRE(LinkedList::toVector(sumListsForward(l1, l3)) == std::vector<int>({1,0,1,2}));
  REQUIRE(LinkedList::toVector(sumListsForward(l1, l4)) == std::vector<int>({1,0,0,1,2}));
}

