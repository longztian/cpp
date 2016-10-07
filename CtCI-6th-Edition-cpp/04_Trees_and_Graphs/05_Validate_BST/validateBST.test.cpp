#include "catch.hpp"
#include "validateBST.hpp"

namespace BT = BinaryTree;

TEST_CASE("validateBST test", "[validateBST]") {
  REQUIRE(validateBST(BT::create("[]")) == true);
  REQUIRE(validateBST(BT::create("[1]")) == true);
  REQUIRE(validateBST(BT::create("[3,2,1]")) == true);
  REQUIRE(validateBST(BT::create("[1,null,2,null,3]")) == true);
  REQUIRE(validateBST(BT::create("[2,1,null,null,3]")) == true);
  REQUIRE(validateBST(BT::create("[2,1,null,null,1]")) == false);
  REQUIRE(validateBST(BT::create("[2,3,null,null,3]")) == false);
}
