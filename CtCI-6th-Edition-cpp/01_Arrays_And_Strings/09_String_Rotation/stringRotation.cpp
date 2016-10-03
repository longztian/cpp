#include <algorithm>
#include "stringRotation.hpp"

bool isSubstring(const std::string& src, const std::string& sub) {
  return std::search(src.cbegin(), src.cend(), sub.cbegin(), sub.cend()) != src.cend();
}

bool stringRotation(const std::string& origin, const std::string& rotation) {
  if (origin.length() != rotation.length()) return false;
  return isSubstring(std::string(origin).append(origin), rotation);
}
