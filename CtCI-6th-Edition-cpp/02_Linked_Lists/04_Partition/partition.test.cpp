#include "catch.hpp"
#include "partition.hpp"

TEST_CASE("partition test", "[partition]") {
  auto head = LinkedList::create({1,5,2,4,3});
  partition(head, 3);
  REQUIRE(LinkedList::toVector(head) == std::vector<int>({1,2,5,4,3}));
}

