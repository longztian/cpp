#include <vector>
#include "checkPermutation.hpp"

bool checkPermutation(const std::string& s, const std::string& p) {
  if (s.length() != p.length()) return false;
  if (s.empty() && p.empty()) return true;

  // 1. use two count vectors
  // std::vector<int> sCount(128, 0), pCount(128, 0);

  // for (auto c : s) {
  //   sCount[c] += 1;
  // }

  // for (auto c : p) {
  //   pCount[c] += 1;
  // }

  // for (auto i = 0; i < 128; ++i) {
  //   if (sCount[i] != pCount[i]) return false;
  // }
  //
  // 2. use single count vector
  std::vector<int> count(128, 0);

  for (auto c : s) {
    count[c] += 1;
  }

  for (auto c : p) {
    count[c] -= 1;
  }

  for (auto i = 0; i < 128; ++i) {
    if (count[i] != 0) return false;
  }

  return true;
}
