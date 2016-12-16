#ifndef QLTEST_STAT_ISTAT_HPP_
#define QLTEST_STAT_ISTAT_HPP_

#include <cstdint>
#include <string>
#include "../Trade.hpp"

namespace QLTest {
namespace Stat {

using std::int64_t;

class IStat {
 public:
  virtual ~IStat() = default;

  virtual std::string getName() const             = 0;
  virtual void        add(const QLTest::Trade& t) = 0;
  virtual void        clear()                     = 0;
  virtual int64_t     getResult() const           = 0;
};

}  // namespace Stat
}  // namespace QLTest

#endif  // QLTEST_STAT_ISTAT_HPP_
