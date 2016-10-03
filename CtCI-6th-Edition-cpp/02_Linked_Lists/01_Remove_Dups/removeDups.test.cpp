#include "catch.hpp"
#include "LinkedList.hpp"
#include "removeDups.hpp"

TEST_CASE("will remove duplicates", "[removeDups]") {
  p_node_t head = LinkedList::create({1,2,1,3,2,4});
  removeDups(head);
  REQUIRE(LinkedList::toVector(head) == std::vector<int>({1,2,3,4}));
}

TEST_CASE("not change list when there is no duplicate", "[removeDups]") {
  p_node_t head = LinkedList::create({1,2,3,4});
  removeDups(head);
  REQUIRE(LinkedList::toVector(head) == std::vector<int>({1,2,3,4}));
}
