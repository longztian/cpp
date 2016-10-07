#include "catch.hpp"
#include "firstCommonAncestor.hpp"

namespace BT = BinaryTreeShared;

TEST_CASE("firstCommonAncestor test", "[firstCommonAncestor]") {
  auto root = BT::create("[]");
  auto n1 = root, n2 = root;
  REQUIRE(firstCommonAncestor(root, n1, n2) == nullptr);
}
