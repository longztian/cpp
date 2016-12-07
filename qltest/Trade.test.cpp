#include "catch.hpp"
#include "Trade.hpp"

TEST_CASE("load trade from record", "[Trade]") {
  QLTest::Trade trade;
  trade.load("51300193149,abc,107,194");

  REQUIRE(trade.time == 51300193149);
  REQUIRE(trade.symbolId == 28);
  REQUIRE(trade.quantity == 107);
  REQUIRE(trade.price == 194);
}
