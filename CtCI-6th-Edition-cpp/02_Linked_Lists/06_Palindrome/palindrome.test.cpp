#include "catch.hpp"
#include "palindrome.hpp"

TEST_CASE("palindrome test", "[palindrome]") {
  REQUIRE(palindrome(LinkedList::create({})) == true);
  REQUIRE(palindrome(LinkedList::create({1})) == true);
  REQUIRE(palindrome(LinkedList::create({1,2})) == false);
  REQUIRE(palindrome(LinkedList::create({1,2,1})) == true);
  REQUIRE(palindrome(LinkedList::create({1,2,3})) == false);
  REQUIRE(palindrome(LinkedList::create({1,2,2,1})) == true);
}
