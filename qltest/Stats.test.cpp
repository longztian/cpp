#include <sstream>
#include "catch.hpp"
#include "Stats.hpp"

TEST_CASE("test output stream", "[Stats]") {
  QLTest::Trade trade;
  QLTest::Stats stats;
  std::ostringstream ss;

  trade.load("51300193149,abc,10,15");
  stats.add(trade);
  ss << stats;
  REQUIRE(ss.str() == "0,10,15,15");

  ss.str("");
  trade.load("51300193155,abc,10,25");
  stats.add(trade);
  ss << stats;
  REQUIRE(ss.str() == "6,20,20,25");

  ss.str("");
  trade.load("51300193156,abc,20,10");
  stats.add(trade);
  ss << stats;
  REQUIRE(ss.str() == "6,40,15,25");
}
