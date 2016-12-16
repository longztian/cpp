#include "catch.hpp"
#include "MaxTimeGap.hpp"

using QLTest::Trade;
using Stat = QLTest::Stat::MaxTimeGap;

TEST_CASE("MaxTimeGap test", "[MaxTimeGap]") {
  Trade trade;
  Stat stat;

  trade.load("51300193149,abc,10,15");
  stat.add(trade);
  REQUIRE(stat.getResult() == 0);

  trade.load("51300193155,abc,10,25");
  stat.add(trade);
  REQUIRE(stat.getResult() == 6);

  trade.load("51300193156,abc,20,10");
  stat.add(trade);
  REQUIRE(stat.getResult() == 6);
}
