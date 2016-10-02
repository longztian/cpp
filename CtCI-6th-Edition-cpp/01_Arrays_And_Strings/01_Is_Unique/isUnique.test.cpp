#include "catch.hpp"
#include "isUnique.hpp"

TEST_CASE("true if a string is empty", "[isUnique]") {
  REQUIRE(isUnique("") == true);
}

TEST_CASE("true if a string has all unique characters", "[isUnique]") {
  REQUIRE(isUnique("abcde") == true);
}

TEST_CASE("false if a string has duplicate characters", "[isUnique]") {
  REQUIRE(isUnique("abbde") == false);
  REQUIRE(isUnique("abcda") == false);
}
