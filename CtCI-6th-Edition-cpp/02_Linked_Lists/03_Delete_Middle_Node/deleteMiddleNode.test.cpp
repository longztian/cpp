#include "catch.hpp"
#include "deleteMiddleNode.hpp"

TEST_CASE("deleteMiddleNode test", "[deleteMiddleNode]") {
  p_node_t head = LL::create({1,2,3,4});
  deleteMiddleNode(head->next);
  REQUIRE(LL::toVector(head) == std::vector<int>({1,3,4}));
}

