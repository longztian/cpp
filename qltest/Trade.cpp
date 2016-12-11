#include <cstdlib>
#include "Symbol.hpp"
#include "Trade.hpp"

namespace QLTest {

void Trade::load(const char* record) {
  char* p  = nullptr;
  time     = std::strtoll(record, &p, 10);
  symbolId = Symbol::getId(p + 1);

  p += 5;
  quantity = std::strtol(p, &p, 10);
  price    = std::strtol(p + 1, nullptr, 10);
}

}  // namespace QLTest
