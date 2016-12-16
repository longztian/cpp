#ifndef QLTEST_STAT_TOTALVOLUME_HPP_
#define QLTEST_STAT_TOTALVOLUME_HPP_

#include "IStat.hpp"

namespace QLTest {
namespace Stat {

class TotalVolume : public IStat {
 public:
  TotalVolume() : myTotalVolume(0) {}

  std::string getName() const             override;
  void        add(const QLTest::Trade& t) override;
  void        clear()                     override;
  int64_t     getResult() const           override;

 private:
  int64_t myTotalVolume;
};

}  // namespace Stat
}  // namespace QLTest

#endif  // QLTEST_STAT_TOTALVOLUME_HPP_
