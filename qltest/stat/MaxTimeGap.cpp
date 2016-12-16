#include <algorithm>
#include "MaxTimeGap.hpp"

namespace QLTest {
namespace Stat {

std::string MaxTimeGap::getName() const {
  return "MaxTimeGap";
}

void MaxTimeGap::add(const QLTest::Trade& t) {
  if (myLastTime >= 0) myMaxTimeGap = std::max(myMaxTimeGap, t.time - myLastTime);
  myLastTime = t.time;
}

void MaxTimeGap::clear() {
  myLastTime = -1;
  myMaxTimeGap = 0;
}

int64_t MaxTimeGap::getResult() const {
  return myMaxTimeGap;
}

}  // namespace Stat
}  // namespace QLTest
