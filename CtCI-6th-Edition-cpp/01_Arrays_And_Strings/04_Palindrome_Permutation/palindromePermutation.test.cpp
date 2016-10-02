#include "catch.hpp"
#include "palindromePermutation.hpp"

TEST_CASE("return true for palindrome", "[palindromePermutation]") {
  REQUIRE(palindromePermutation("abcabc") == true);
  REQUIRE(palindromePermutation("abcabcd") == true);
  REQUIRE(palindromePermutation("abcabcd,") == true);
  REQUIRE(palindromePermutation("Tact Coa") == true);
}

TEST_CASE("return false for non-palindrome", "[palindromePermutation]") {
  REQUIRE(palindromePermutation("Tact Coab") == false);
}
