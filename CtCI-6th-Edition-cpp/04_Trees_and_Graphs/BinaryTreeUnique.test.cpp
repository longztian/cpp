#include "catch.hpp"
#include "BinaryTreeUnique.hpp"

namespace BT = BinaryTreeUnique;

TEST_CASE("BinaryTreeUnique: create and toString, tailing 'null's are optional", "[BinaryTreeUnique]") {
  auto p = BT::create("[]");
  REQUIRE(p == nullptr);

  p = BT::create("[null]");
  REQUIRE(p == nullptr);

  p = BT::create("[1]");
  REQUIRE(p->data == 1);
  REQUIRE(p->left == nullptr);
  REQUIRE(p->right == nullptr);

  p->left = BT::create("[2,null,3]");
  p->right = BT::create("[4,5,null]");
  REQUIRE(BT::toString(p) == "[1,2,null,3,null,null,4,5,null,null,null]");


  p = BT::create("[1,2,null,3,null,null,4,5,null,null,null]");
  REQUIRE(p->data == 1);
  REQUIRE(p->left->data == 2);
  REQUIRE(p->right->data == 4);
  REQUIRE(p->left->left == nullptr);
  REQUIRE(p->left->right->data == 3);
  REQUIRE(p->right->left->data == 5);
  REQUIRE(p->right->right == nullptr);
  REQUIRE(BT::toString(p) == "[1,2,null,3,null,null,4,5,null,null,null]");


  p = BT::create("[1,2,null,3,null,null,4,5]");
  REQUIRE(BT::toString(p) == "[1,2,null,3,null,null,4,5,null,null,null]");
}


TEST_CASE("BinaryTreeUnique: equal", "[BinaryTreeUnique]") {
  REQUIRE(BT::equal(BT::create("[1]"), BT::create("[]")) == false);
  REQUIRE(BT::equal(BT::create("[1]"), BT::create("[2]")) == false);
  REQUIRE(BT::equal(BT::create("[1]"), BT::create("[1]")) == true);

  auto p1 = BT::create("[1,2,null,3,null,null,4,5]");
  auto p2 = BT::create("[1,2,null,3,null,null,4,5,null,null,null]");
  REQUIRE(BT::equal(p1, p2) == true);
}
