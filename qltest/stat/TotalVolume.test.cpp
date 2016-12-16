#include "catch.hpp"
#include "TotalVolume.hpp"

using QLTest::Trade;
using Stat = QLTest::Stat::TotalVolume;

TEST_CASE("TotalVolume test", "[TotalVolume]") {
  Trade trade;
  Stat stat;

  trade.load("51300193149,abc,10,15");
  stat.add(trade);
  REQUIRE(stat.getResult() == 10);

  trade.load("51300193155,abc,10,25");
  stat.add(trade);
  REQUIRE(stat.getResult() == 20);

  trade.load("51300193156,abc,20,10");
  stat.add(trade);
  REQUIRE(stat.getResult() == 40);
}
