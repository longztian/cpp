#include "WeightedAveragePrice.hpp"

namespace QLTest {
namespace Stat {

std::string WeightedAveragePrice::getName() const {
  return "WeightedAveragePrice";
}

void WeightedAveragePrice::add(const QLTest::Trade& t) {
  myTotalVolume += t.quantity;
  myTotalPrice += t.price * t.quantity;
}

void WeightedAveragePrice::clear() {
  myTotalVolume = 0;
  myTotalPrice = 0;
}

int64_t WeightedAveragePrice::getResult() const {
  return myTotalPrice / myTotalVolume;
}

}  // namespace Stat
}  // namespace QLTest
