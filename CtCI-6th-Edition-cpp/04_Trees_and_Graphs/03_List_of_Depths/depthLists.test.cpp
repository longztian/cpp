#include "catch.hpp"
#include "depthLists.hpp"

namespace BT = BinaryTree;

TEST_CASE("depthLists test", "[depthLists]") {
  auto p = BT::create("[]");
  auto l = depthLists(p);
  REQUIRE(l.empty());

  p = BT::create("[1]");
  l = depthLists(p);
  REQUIRE(l == list_vector_t({{1}}));

  p = BT::create("[1,2,3]");
  l = depthLists(p);
  REQUIRE(l == list_vector_t({{1},{2},{3}}));

  p = BT::create("[1,2,3,4,null,null,null,null,5,null,6]");
  l = depthLists(p);
  REQUIRE(l == list_vector_t({{1},{2,5},{3,6},{4}}));
}
