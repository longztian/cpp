#include "TotalVolume.hpp"

namespace QLTest {
namespace Stat {

std::string TotalVolume::getName() const {
  return "TotalVolume";
}

void TotalVolume::add(const QLTest::Trade& t) {
  myTotalVolume += t.quantity;
}

void TotalVolume::clear() {
  myTotalVolume = 0;
}

int64_t TotalVolume::getResult() const {
  return myTotalVolume;
}

}  // namespace Stat
}  // namespace QLTest
