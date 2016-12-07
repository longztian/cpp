#include <sstream>
#include "catch.hpp"
#include "Stats.hpp"

TEST_CASE("add trade to statistics", "[Stats]") {
  QLTest::Trade trade;
  QLTest::Stats stats;

  trade.load("51300193149,abc,10,15");
  stats.add(trade);
  REQUIRE(stats.getMaxTimeGap() == 0);
  REQUIRE(stats.getTotalVolume() == 10);
  REQUIRE(stats.getWeightedAveragePrice() == 15);
  REQUIRE(stats.getMaxPrice() == 15);

  trade.load("51300193155,abc,10,25");
  stats.add(trade);
  REQUIRE(stats.getMaxTimeGap() == 6);
  REQUIRE(stats.getTotalVolume() == 20);
  REQUIRE(stats.getWeightedAveragePrice() == 20);
  REQUIRE(stats.getMaxPrice() == 25);

  trade.load("51300193156,abc,20,10");
  stats.add(trade);
  REQUIRE(stats.getMaxTimeGap() == 6);
  REQUIRE(stats.getTotalVolume() == 40);
  REQUIRE(stats.getWeightedAveragePrice() == 15);
  REQUIRE(stats.getMaxPrice() == 25);
}

TEST_CASE("test output stream", "[Stats]") {
  QLTest::Trade trade;
  QLTest::Stats stats;

  trade.load("51300193149,abc,10,15");
  stats.add(trade);
  trade.load("51300193155,abc,10,25");
  stats.add(trade);
  trade.load("51300193156,abc,20,10");
  stats.add(trade);

  std::ostringstream ss;
  ss << stats;
  REQUIRE(ss.str() == "6,40,15,25");
}
