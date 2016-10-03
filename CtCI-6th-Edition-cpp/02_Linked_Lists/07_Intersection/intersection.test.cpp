#include "catch.hpp"
#include "intersection.hpp"

TEST_CASE("intersection test", "[intersection]") {
  REQUIRE(intersection(nullptr, nullptr) == nullptr);
}
