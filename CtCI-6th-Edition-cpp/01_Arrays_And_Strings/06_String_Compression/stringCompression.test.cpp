#include "catch.hpp"
#include "stringCompression.hpp"

TEST_CASE("will compress", "[stringCompression]") {
  REQUIRE(stringCompression("aabcccccaaa") == "a2b1c5a3");
  REQUIRE(stringCompression("aabcccccaaaA") == "a2b1c5a3A1");
}


TEST_CASE("will not compress if not shorter", "[stringCompression]") {
  REQUIRE(stringCompression("abc") == "abc");
  REQUIRE(stringCompression("abb") == "abb");
}

