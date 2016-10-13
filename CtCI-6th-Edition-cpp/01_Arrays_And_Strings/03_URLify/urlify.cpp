#include <algorithm>
#include "urlify.hpp"

int urlify(std::string& s, int n) {
  if (n == 0) return n;

  int nSpace = std::count(s.cbegin(), s.cbegin() + n, ' ');
  if (nSpace == 0) return n;

  auto iOld = s.begin() + n - 1;
  auto iNew = iOld + nSpace * 2;
  while (iNew > iOld) {
    if (*iOld == ' ') {
      *iNew = '0';
      *(iNew - 1) = '2';
      *(iNew - 2) = '%';
      iNew -= 2;
    } else {
      *iNew = *iOld;
    }

    iNew -= 1;
    iOld -= 1;
  }

  return n + nSpace * 2;
}
