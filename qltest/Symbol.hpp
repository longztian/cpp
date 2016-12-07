#ifndef QLTEST_SYMBOL_HPP_
#define QLTEST_SYMBOL_HPP_

#include <cstdint>
#include <string>

namespace QLTest {
namespace Symbol {

using std::int32_t;

const int32_t BASE = 26;
const int32_t BASE2 = BASE * BASE;
const int32_t BASE3 = BASE * BASE2;

inline
int32_t getId(const char* p) {
  return (*p - 'a') * BASE2 + (*(p + 1) - 'a') * BASE + (*(p + 2) - 'a');
}

inline
void getSymbol(int32_t id, std::string& symbol) {
  symbol[0] = 'a' + id / BASE2;
  symbol[1] = 'a' + id % BASE2 / BASE;
  symbol[2] = 'a' + id % BASE;
}

}  // namespace Symbol
}  // namespace QLTest

#endif  // QLTEST_SYMBOL_HPP_
