#include "catch.hpp"
#include "rotateMatrix.hpp"

TEST_CASE("DESCRIPTION", "[rotateMatrix]") {
  std::vector<std::vector<int>> m = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  },
  rotate = {
    {7,4,1},
    {8,5,2},
    {9,6,3}
  };
  rotateMatrix(m);
  REQUIRE(m == rotate);
}

