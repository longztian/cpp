#include <vector>
#include "isUnique.hpp"

bool isUnique(const std::string& s) {
  // 1. brute force: O(n^2)
  // for (auto i = 0; i < s.length(); ++i) {
  //   for (auto j = i+1; j < s.length(); ++j) {
  //     if (s[i] ==s[j]) return false;
  //   }
  // }

  // 2. use char map
  std::vector<bool> charSet(128, false);
  for (auto c : s) {
    if (charSet[c]) return false;
    charSet[c] = true;
  }

  return true;
}
