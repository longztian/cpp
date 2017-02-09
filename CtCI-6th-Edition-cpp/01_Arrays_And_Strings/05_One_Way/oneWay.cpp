#include <vector>
#include "oneWay.hpp"

bool oneDiff(const std::string& shortStr, const std::string& longStr) {
  int nMiss = 0;
  auto iS = shortStr.cbegin(), iL = longStr.cbegin();
  while (iS != shortStr.cend()) {
    if (*iS == *iL) {
      iS += 1;  // important, move both when equal
      iL += 1;
    } else {
      if (nMiss == 1) return false;
      nMiss += 1;
      iL += 1;  // only move iL when found the missing charactor
    }
  }

  return iL == longStr.cend() ? (nMiss == 1) : (nMiss == 0);
}

bool oneWay(const std::string& s1, const std::string& s2) {
  if (s1.length() == s2.length()) {
    // check equal or replace
    int nDiff = 0;

    for (size_t i = 0; i < s1.length(); ++i) {
      if (s1[i] != s2[i]) nDiff += 1;
      if (nDiff > 1) return false;
    }

    return true;
  } else if (s1.length() == s2.length() - 1) {
    // insert
    return oneDiff(s1, s2);
  } else if (s1.length() == s2.length() + 1) {
    // remove
    return oneDiff(s2, s1);
  }

  return false;
}
