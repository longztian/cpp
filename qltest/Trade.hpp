#ifndef QLTEST_TRADE_HPP_
#define QLTEST_TRADE_HPP_

#include <cstdint>
#include <string>

namespace QLTest {

using std::int32_t;
using std::int64_t;

struct Trade {
  int64_t time;
  int32_t symbolId;
  int32_t quantity;
  int32_t price;

  void load(const std::string& record);
};

}  // namespace QLTest

#endif  // QLTEST_TRADE_HPP_
