#include "catch.hpp"
#include "deleteMiddleNode.hpp"

TEST_CASE("deleteMiddleNode test", "[deleteMiddleNode]") {
  p_node_t head = LinkedList::create({1,2,3,4});
  deleteMiddleNode(head->next);
  REQUIRE(LinkedList::toVector(head) == std::vector<int>({1,3,4}));
}

