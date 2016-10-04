#include "catch.hpp"
#include "minStack.hpp"

TEST_CASE("minStack test", "[minStack]") {
  auto s = minStack();
  REQUIRE(s.empty() == true);

  s.push(3);
  REQUIRE(s.empty() == false);
  REQUIRE(s.peek() == 3);
  REQUIRE(s.min() == 3);

  s.push(2);
  REQUIRE(s.peek() == 2);
  REQUIRE(s.min() == 2);

  s.push(5);
  REQUIRE(s.peek() == 5);
  REQUIRE(s.min() == 2);

  REQUIRE(s.pop() == 5);
  REQUIRE(s.min() == 2);
  REQUIRE(s.pop() == 2);
  REQUIRE(s.min() == 3);
  REQUIRE(s.pop() == 3);
  REQUIRE(s.empty() == true);
}
