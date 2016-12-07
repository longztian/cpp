#include <algorithm>
#include "Stats.hpp"

namespace QLTest {

void Stats::add(const Trade& trade) {
  myMaxTimeGap = myLastTime >= 0 ? std::max(myMaxTimeGap, trade.time - myLastTime) : 0;
  myMaxPrice = std::max(myMaxPrice, trade.price);
  myTotalVolume += trade.quantity;
  myTotalPrice += trade.price * trade.quantity;

  myLastTime = trade.time;
}

}  // namespace QLTest

std::ostream& operator << (std::ostream& os, const QLTest::Stats& rhs) {
  os << rhs.getMaxTimeGap()
     << ','
     << rhs.getTotalVolume()
     << ','
     << rhs.getWeightedAveragePrice()
     << ','
     << rhs.getMaxPrice();

  return os;
}
