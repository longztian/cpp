#include "catch.hpp"
#include "stackOfPlates.hpp"

TEST_CASE("stackOfPlates test", "[stackOfPlates]") {
  auto s = stackOfPlates();
  REQUIRE(s.empty() == true);

  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);
  s.push(7);

  REQUIRE(s.empty() == false);

  REQUIRE(s.popAt(0) == 3);
  REQUIRE(s.popAt(1) == 6);

  REQUIRE(s.peek() == 7);

  REQUIRE(s.pop() == 7);
  REQUIRE(s.pop() == 5);
  REQUIRE(s.pop() == 4);
  REQUIRE(s.pop() == 2);
  REQUIRE(s.pop() == 1);

  REQUIRE(s.empty() == true);
}
