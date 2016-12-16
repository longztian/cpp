#include "MaxPrice.hpp"

namespace QLTest {
namespace Stat {

std::string MaxPrice::getName() const {
  return "MaxPrice";
}

void MaxPrice::add(const QLTest::Trade& t) {
  if (t.price > myMaxPrice) myMaxPrice = t.price;
}

void MaxPrice::clear() {
  myMaxPrice = 0;
}

int64_t MaxPrice::getResult() const {
  return myMaxPrice;
}

}  // namespace Stat
}  // namespace QLTest
