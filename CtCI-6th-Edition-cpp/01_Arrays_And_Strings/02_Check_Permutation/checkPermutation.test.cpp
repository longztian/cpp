#include "catch.hpp"
#include "checkPermutation.hpp"

TEST_CASE("true for empty strings", "[checkPermutation]") {
  REQUIRE(checkPermutation("", "") == true);
}

TEST_CASE("true for permutation strings", "[checkPermutation]") {
  REQUIRE(checkPermutation("abc", "acb") == true);
}

TEST_CASE("false for non-permutation strings", "[checkPermutation]") {
  REQUIRE(checkPermutation("abc", "aac") == false);
  REQUIRE(checkPermutation("abc", "abcc") == false);
}
