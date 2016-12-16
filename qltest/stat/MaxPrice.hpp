#ifndef QLTEST_STAT_MAXPRICE_HPP_
#define QLTEST_STAT_MAXPRICE_HPP_

#include "IStat.hpp"

namespace QLTest {
namespace Stat {

class MaxPrice : public IStat {
 public:
  MaxPrice() : myMaxPrice(0) {}

  std::string getName() const             override;
  void        add(const QLTest::Trade& t) override;
  void        clear()                     override;
  int64_t     getResult() const           override;

 private:
  int64_t myMaxPrice;
};

}  // namespace Stat
}  // namespace QLTest

#endif  // QLTEST_STAT_MAXPRICE_HPP_
