#ifndef QLTEST_STAT_WEIGHTEDAVERAGEPRICE_HPP_
#define QLTEST_STAT_WEIGHTEDAVERAGEPRICE_HPP_

#include "IStat.hpp"

namespace QLTest {
namespace Stat {

class WeightedAveragePrice : public IStat {
 public:
  WeightedAveragePrice() : myTotalVolume(0), myTotalPrice(0) {}

  std::string getName() const             override;
  void        add(const QLTest::Trade& t) override;
  void        clear()                     override;
  int64_t     getResult() const           override;

 private:
  int64_t myTotalVolume;
  int64_t myTotalPrice;
};

}  // namespace Stat
}  // namespace QLTest

#endif  // QLTEST_STAT_WEIGHTEDAVERAGEPRICE_HPP_
