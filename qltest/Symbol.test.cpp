#include "catch.hpp"
#include "Symbol.hpp"

namespace Symbol = ::QLTest::Symbol;

TEST_CASE("get id from symbol string", "[Symbol]") {
  REQUIRE(Symbol::getId("aaa") == 0);
  REQUIRE(Symbol::getId("azz") == Symbol::BASE2 - 1);
  REQUIRE(Symbol::getId("zza") == (Symbol::BASE2 - 1)* Symbol::BASE);
  REQUIRE(Symbol::getId("zzz") == Symbol::BASE3 - 1);
}


TEST_CASE("get symbol from id", "[Symbol]") {
  std::string symbol(3, 'a');
  char* p = const_cast<char*>(symbol.data());  // lack of non-const data() before C++17

  Symbol::getSymbol(0, p);
  REQUIRE(symbol == "aaa");

  Symbol::getSymbol(Symbol::BASE2 - 1, p);
  REQUIRE(symbol == "azz");

  Symbol::getSymbol((Symbol::BASE2 - 1) * Symbol::BASE, p);
  REQUIRE(symbol == "zza");

  Symbol::getSymbol(Symbol::BASE3 - 1, p);
  REQUIRE(symbol == "zzz");
}
