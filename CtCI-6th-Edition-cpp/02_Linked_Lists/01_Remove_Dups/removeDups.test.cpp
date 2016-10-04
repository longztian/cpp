#include "catch.hpp"
#include "removeDups.hpp"

TEST_CASE("will remove duplicates", "[removeDups]") {
  p_node_t head = LL::create({1,2,1,3,2,4});
  removeDups(head);
  REQUIRE(LL::toVector(head) == std::vector<int>({1,2,3,4}));
}

TEST_CASE("not change list when there is no duplicate", "[removeDups]") {
  p_node_t head = LL::create({1,2,3,4});
  removeDups(head);
  REQUIRE(LL::toVector(head) == std::vector<int>({1,2,3,4}));
}
