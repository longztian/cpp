#ifndef QLTEST_STATS_HPP_
#define QLTEST_STATS_HPP_

#include <vector>
#include <ostream>
#include "Trade.hpp"
#include "stat/IStat.hpp"

namespace QLTest {

class Stats {
 public:
  friend std::ostream& operator << (std::ostream& os, const Stats& rhs);

  Stats();
  ~Stats();

  void add(const Trade& trade);

 private:
  std::vector<Stat::IStat*> myStats;
};

std::ostream& operator << (std::ostream& os, const Stats& rhs);

}  // namespace QLTest

#endif  // QLTEST_STATS_HPP_
