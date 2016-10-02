#include "catch.hpp"
#include "urlify.hpp"

TEST_CASE("should convert space to %20", "[urlify]") {
  std::string s("a b c      ");
  int n = urlify(s, 5);
  REQUIRE(s == "a%20b%20c  ");
  REQUIRE(n == 9);
}

TEST_CASE("should not change string if no space", "[urlify]") {
  std::string s("abc      ");
  int n = urlify(s, 3);
  REQUIRE(s == "abc      ");
  REQUIRE(n == 3);
}
