#include "catch.hpp"
#include "minimalTree.hpp"

namespace BT = BinaryTree;

TEST_CASE("minimalTree test", "[minimalTree]") {
  std::vector<int> numbers;
  REQUIRE(minimalTree(numbers) == nullptr);

  numbers.push_back(1);
  REQUIRE(BT::toString(minimalTree(numbers)) == "[1,null,null]");

  numbers.push_back(2);
  REQUIRE(BT::toString(minimalTree(numbers)) == "[2,1,null,null,null]");

  numbers.push_back(3);
  REQUIRE(BT::toString(minimalTree(numbers)) == "[2,1,null,null,3,null,null]");

  numbers.push_back(4);
  REQUIRE(BT::toString(minimalTree(numbers)) == "[3,2,1,null,null,null,4,null,null]");
}
