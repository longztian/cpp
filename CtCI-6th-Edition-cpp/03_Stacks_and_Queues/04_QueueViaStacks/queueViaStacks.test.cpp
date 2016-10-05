#include "catch.hpp"
#include "queueViaStacks.hpp"

TEST_CASE("queueViaStacks test", "[queueViaStacks]") {
  auto q = queueViaStacks();

  REQUIRE(q.empty() == true);
  q.push(1);
  REQUIRE(q.empty() == false);
  q.push(2);
  REQUIRE(q.peek() == 1);
  REQUIRE(q.pop() == 1);
  REQUIRE(q.peek() == 2);
  REQUIRE(q.empty() == false);
  REQUIRE(q.pop() == 2);
  REQUIRE(q.empty() == true);
}
