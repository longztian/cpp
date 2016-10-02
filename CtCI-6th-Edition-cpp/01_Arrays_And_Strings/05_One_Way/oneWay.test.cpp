#include "catch.hpp"
#include "oneWay.hpp"

TEST_CASE("true for zero edit", "[oneWay]") {
  REQUIRE(oneWay("", "") == true);
  REQUIRE(oneWay("abc", "abc") == true);
}

TEST_CASE("true for one insert", "[oneWay]") {
  REQUIRE(oneWay("", "a") == true);
  REQUIRE(oneWay("abc", "abcd") == true);
}

TEST_CASE("true for one remove", "[oneWay]") {
  REQUIRE(oneWay("a", "") == true);
  REQUIRE(oneWay("abc", "ab") == true);
}

TEST_CASE("true for one replace", "[oneWay]") {
  REQUIRE(oneWay("a", "b") == true);
  REQUIRE(oneWay("abc", "adc") == true);
}

TEST_CASE("false for two edits", "[oneWay]") {
  REQUIRE(oneWay("", "ab") == false);
  REQUIRE(oneWay("abc", "a") == false);
  REQUIRE(oneWay("abc", "ade") == false);
  REQUIRE(oneWay("a", "bc") == false);
  REQUIRE(oneWay("abc", "ad") == false);
}

TEST_CASE("book examples", "[oneWay]") {
  REQUIRE(oneWay("pale", "ple") == true);
  REQUIRE(oneWay("pales", "pale") == true);
  REQUIRE(oneWay("pale", "bale") == true);
  REQUIRE(oneWay("pale", "bake") == false);
}
