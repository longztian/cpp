#include "catch.hpp"
#include "WeightedAveragePrice.hpp"

using QLTest::Trade;
using Stat = QLTest::Stat::WeightedAveragePrice;

TEST_CASE("WeightedAveragePrice test", "[WeightedAveragePrice]") {
  Trade trade;
  Stat stat;

  trade.load("51300193149,abc,10,15");
  stat.add(trade);
  REQUIRE(stat.getResult() == 15);

  trade.load("51300193155,abc,10,25");
  stat.add(trade);
  REQUIRE(stat.getResult() == 20);

  trade.load("51300193156,abc,20,10");
  stat.add(trade);
  REQUIRE(stat.getResult() == 15);
}
