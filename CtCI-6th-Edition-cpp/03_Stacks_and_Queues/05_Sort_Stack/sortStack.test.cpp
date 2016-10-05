#include "catch.hpp"
#include "sortStack.hpp"

TEST_CASE("sortStack test", "[sortStack]") {
  Stack s;
  sortStack(s);
  REQUIRE(s.empty() == true);

  s.push(3);
  s.push(1);
  s.push(4);
  s.push(2);
  REQUIRE(s.empty() == false);

  sortStack(s);
  REQUIRE(s.top() == 1);
  s.pop();
  REQUIRE(s.top() == 2);
  s.pop();
  REQUIRE(s.top() == 3);
  s.pop();
  REQUIRE(s.top() == 4);
  s.pop();

  REQUIRE(s.empty() == true);
}
