#include "catch.hpp"
#include "BinaryTree.hpp"

namespace BT = BinaryTree;

TEST_CASE("create and toString, tailing 'null's are optional", "[Tree]") {
  auto p = BT::create("[1]");
  REQUIRE(p->data == 1);
  REQUIRE(p->left == nullptr);
  REQUIRE(p->right == nullptr);

  p->left = BT::create("[2,null,3]");
  p->right = BT::create("[4,5,null]");

  REQUIRE(BT::toString(p) == "[1,2,null,3,null,null,4,5,null,null,null]");

  p = BT::create("[1,2,null,3,null,null,4,5,null,null,null]");
  REQUIRE(BT::toString(p) == "[1,2,null,3,null,null,4,5,null,null,null]");

  p = BT::create("[1,2,null,3,null,null,4,5]");
  REQUIRE(BT::toString(p) == "[1,2,null,3,null,null,4,5,null,null,null]");
}
