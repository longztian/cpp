#ifndef QLTEST_STATS_HPP_
#define QLTEST_STATS_HPP_

#include <cstdint>
#include <ostream>
#include "Trade.hpp"

namespace QLTest {

using std::int32_t;
using std::int64_t;

class Stats {
 public:
  inline const int64_t getMaxTimeGap()           const { return myMaxTimeGap; }
  inline const int64_t getTotalVolume()          const { return myTotalVolume; }
  inline const int32_t getWeightedAveragePrice() const { return myTotalPrice / myTotalVolume; }
  inline const int32_t getMaxPrice()             const { return myMaxPrice; }

  Stats() : myLastTime(-1), myMaxTimeGap(0), myTotalVolume(0), myTotalPrice(0), myMaxPrice(0) {}
  void add(const Trade& trade);

 private:
  int64_t myLastTime;
  int64_t myMaxTimeGap;
  int64_t myTotalVolume;
  int64_t myTotalPrice;
  int32_t myMaxPrice;
};

}  // namespace QLTest

// overload output operator
std::ostream& operator << (std::ostream& os, const QLTest::Stats& rhs);

#endif  // QLTEST_STATS_HPP_
