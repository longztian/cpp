#include <vector>
#include <algorithm>
#include "palindromePermutation.hpp"

bool palindromePermutation(const std::string& s) {
  // fetch letters
  // to lower case
  // check letter counts (don't need the first two steps)
  std::vector<int> count(26, 0);

  for (auto c : s) {
    if(c >= 'a' && c <= 'z') {
      count[c-'a'] += 1;
    }
    else if (c >= 'A' && c <= 'Z') {
      count[c-'A'] += 1;
    }
  }

  return !(std::count_if(count.cbegin(), count.cend(), [](int n){
    return n % 2 == 1;
  }) > 1);
}
