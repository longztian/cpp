#include "catch.hpp"
#include "LinkedList.hpp"
#include "kthToLast.hpp"

TEST_CASE("kthToLast test", "[kthToLast]") {
  p_node_t head = LinkedList::create({1,2,3,4,5,6,7});
  REQUIRE(LinkedList::toVector(kthToLast(head, 0)) == std::vector<int>({1,2,3,4,5,6,7}));
  REQUIRE(LinkedList::toVector(kthToLast(head, 2)) == std::vector<int>({2,3,4,5,6,7}));
  REQUIRE(LinkedList::toVector(kthToLast(head, 4)) == std::vector<int>({4,5,6,7}));

  p_node_t empty = LinkedList::create({});
  REQUIRE(LinkedList::toVector(kthToLast(empty, 1)) == std::vector<int>({}));
}

