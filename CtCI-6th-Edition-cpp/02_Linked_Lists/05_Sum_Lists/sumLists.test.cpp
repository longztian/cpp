#include "catch.hpp"
#include "sumLists.hpp"

TEST_CASE("sumLists test", "[sumLists]") {
  auto l1 = LinkedList::create({7,1,6});
  auto l2 = LinkedList::create({5,9,2});
  auto l3 = LinkedList::create({5,9,3});
  REQUIRE(LinkedList::toVector(sumLists(l1, l2)) == std::vector<int>({2,1,9}));
  REQUIRE(LinkedList::toVector(sumLists(l1, l3)) == std::vector<int>({2,1,0,1}));
}

