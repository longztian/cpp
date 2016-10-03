#include "catch.hpp"
#include "zeroMatrix.hpp"

TEST_CASE("fill zero if find zero", "[zeroMatrix]") {
  std::vector<std::vector<int>> input = {
    {1,2,3},
    {4,0,6},
    {7,0,0},
    {10,11,12}
  },
  expect = {
    {1,0,0},
    {0,0,0},
    {0,0,0},
    {10,0,0}
  };
  zeroMatrix(input);
  REQUIRE(input == expect);
}

TEST_CASE("not change matrix if no zero", "[zeroMatrix]") {
  std::vector<std::vector<int>> input = {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {10,11,12}
  },
  expect = {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {10,11,12}
  };
  zeroMatrix(input);
  REQUIRE(input == expect);
}

