#ifndef QLTEST_STAT_MAXTIMEGAP_HPP_
#define QLTEST_STAT_MAXTIMEGAP_HPP_

#include "IStat.hpp"

namespace QLTest {
namespace Stat {

class MaxTimeGap : public IStat {
 public:
  MaxTimeGap() : myLastTime(-1), myMaxTimeGap(0) {}

  std::string getName() const             override;
  void        add(const QLTest::Trade& t) override;
  void        clear()                     override;
  int64_t     getResult() const           override;

 private:
  int64_t myLastTime;
  int64_t myMaxTimeGap;
};

}  // namespace Stat
}  // namespace QLTest

#endif  // QLTEST_STAT_MAXTIMEGAP_HPP_
