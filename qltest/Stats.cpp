#include "Stats.hpp"
#include "stat/MaxTimeGap.hpp"
#include "stat/MaxPrice.hpp"
#include "stat/TotalVolume.hpp"
#include "stat/WeightedAveragePrice.hpp"

namespace QLTest {

Stats::Stats() : myStats({
  new Stat::MaxTimeGap(),
  new Stat::TotalVolume(),
  new Stat::WeightedAveragePrice(),
  new Stat::MaxPrice()
}) {}

Stats::~Stats() {
  for (auto p : myStats) delete p;
}

void Stats::add(const Trade& trade) {
  for (auto p : myStats) p->add(trade);
}

std::ostream& operator << (std::ostream& os, const Stats& rhs) {
  if (!rhs.myStats.empty())
    os << rhs.myStats[0]->getResult();

  for (int i = 1, n = rhs.myStats.size(); i < n; ++i)
    os << ',' << rhs.myStats[i]->getResult();

  return os;
}

}  // namespace QLTest
