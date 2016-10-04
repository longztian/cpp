#include "catch.hpp"
#include "Stack.hpp"

TEST_CASE("stack test", "[Stack]") {
  Stack s;
  REQUIRE(s.empty() == true);
  s.push(1);
  REQUIRE(s.empty() == false);
  REQUIRE(s.peek() == 1);
  s.push(2);
  REQUIRE(s.peek() == 2);
  REQUIRE(s.pop() == 2);
  REQUIRE(s.peek() == 1);
  REQUIRE(s.empty() == false);
  REQUIRE(s.pop() == 1);
  REQUIRE(s.empty() == true);
}
