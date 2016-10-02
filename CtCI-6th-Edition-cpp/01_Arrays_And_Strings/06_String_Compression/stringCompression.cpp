#include "stringCompression.hpp"

std::string stringCompression(const std::string& s) {
  if(s.length() < 3) return s;

  std::string cmp;
  cmp.reserve(s.length());

  auto pB = s.data(), pE = pB + 1, end = s.data() + s.length();
  while (pE != end) {
    // scan for the same character
    while (*pB == *pE && pE != end) {
      pE += 1;
    }

    std::string count = std::to_string(pE - pB);

    if (pE == end) {
      // hit end
      if (cmp.length() + 1 + count.length() < s.length()) {
        cmp.append(1, *pB);
        cmp.append(count);
      }
      else {
        return s;
      }
    }
    else {
      // still have characters
      if (pE == end - 1) {
        // only have one character left
        if (cmp.length() + 3 + count.length() < s.length()) {
          cmp.append(1, *pB);
          cmp.append(count);
          cmp.append(1, *pE);
          cmp.append("1");
          return cmp;
        }
        else {
          return s;
        }
      }
      else {
        if (cmp.length() + 1 + count.length() < s.length()) {
          cmp.append(1, *pB);
          cmp.append(count);
        }
        else {
          return s;
        }
        // move to next character
        pB = pE;
        pE = pB + 1;
      }
    }
  }

  return cmp;
}
