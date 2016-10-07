#include "catch.hpp"
#include "getNext.hpp"

namespace BT = DoubleBinaryTree;

TEST_CASE("getNext test", "[getNext]") {
  auto p = BT::create("[]");
  REQUIRE(getNext(p) == nullptr);

  p = BT::create("[2,1,null,null,3]");
  REQUIRE(getNext(p->left)->data == 2);

  p = BT::create("[2,1,null,null,5,4,3]");
  REQUIRE(getNext(p)->data == 3);
}
