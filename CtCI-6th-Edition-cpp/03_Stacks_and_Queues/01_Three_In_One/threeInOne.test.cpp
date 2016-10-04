#include "catch.hpp"
#include "threeInOne.hpp"

TEST_CASE("threeInOne test", "[threeInOne]") {
  p_stack_t s1, s2, s3;

  threeInOne(s1, s2, s3);
  REQUIRE(s1->empty() == true);
  REQUIRE(s2->empty() == true);
  REQUIRE(s3->empty() == true);

  s1->push(1);
  s2->push(2);
  s3->push(3);
  REQUIRE(s1->empty() == false);
  REQUIRE(s2->empty() == false);
  REQUIRE(s3->empty() == false);

  s1->push(4);
  s2->push(5);
  s3->push(6);
  REQUIRE(s1->peek() == 4);
  REQUIRE(s2->peek() == 5);
  REQUIRE(s3->peek() == 6);

  REQUIRE(s1->pop() == 4);
  REQUIRE(s2->pop() == 5);
  REQUIRE(s3->pop() == 6);

  REQUIRE(s1->empty() == false);
  REQUIRE(s2->empty() == false);
  REQUIRE(s3->empty() == false);

  REQUIRE(s1->pop() == 1);
  REQUIRE(s2->pop() == 2);
  REQUIRE(s3->pop() == 3);

  REQUIRE(s1->empty() == true);
  REQUIRE(s2->empty() == true);
  REQUIRE(s3->empty() == true);
}
