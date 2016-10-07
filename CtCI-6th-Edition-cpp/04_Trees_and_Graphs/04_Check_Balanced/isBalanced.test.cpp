#include "catch.hpp"
#include "isBalanced.hpp"

namespace BT = BinaryTree;

TEST_CASE("isBalanced test", "[isBalanced]") {
  auto tree = BT::create("[]");
  REQUIRE(isBalanced(tree) == true);

  tree = BT::create("[1]");
  REQUIRE(isBalanced(tree) == true);

  tree = BT::create("[1,2]");
  REQUIRE(isBalanced(tree) == true);

  tree = BT::create("[1,null,2]");
  REQUIRE(isBalanced(tree) == true);

  tree = BT::create("[1,2,3]");
  REQUIRE(isBalanced(tree) == false);

  tree = BT::create("[1,2,3,null,null,4]");
  REQUIRE(isBalanced(tree) == false);

  tree = BT::create("[1,2,3,null,null,null,4]");
  REQUIRE(isBalanced(tree) == true);
}
