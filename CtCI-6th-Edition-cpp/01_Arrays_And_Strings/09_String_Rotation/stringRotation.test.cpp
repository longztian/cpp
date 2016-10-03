#include "catch.hpp"
#include "stringRotation.hpp"

TEST_CASE("true for rotation", "[stringRotation]") {
  REQUIRE(stringRotation("test", "estt") == true);
  REQUIRE(stringRotation("test", "ttes") == true);
}

TEST_CASE("false if not a rotation", "[stringRotation]") {
  REQUIRE(stringRotation("test", "est") == false);
  REQUIRE(stringRotation("test", "estte") == false);
  REQUIRE(stringRotation("abca", "bcab") == false);
}

