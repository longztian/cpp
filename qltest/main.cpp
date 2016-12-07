#include <cstdint>
#include <string>
#include <iostream>
#include <fstream>
#include "Symbol.hpp"
#include "Trade.hpp"
#include "Stats.hpp"

const char * const infile = "input.csv";
const char * const outfile = "output.csv";

namespace Symbol = ::QLTest::Symbol;

using std::int32_t;

const int32_t N = Symbol::BASE3;

int main() {
  // use stack for speed
  QLTest::Stats tradeStats[N];

  {  // load trade records from input file
    std::ifstream in(infile);
    if (!in) {
      std::cerr << "Couldn't open file " << infile << std::endl;
      return 1;
    }

    std::string line;
    QLTest::Trade trade;
    while (getline(in, line)) {
      trade.load(line);
      tradeStats[trade.symbolId].add(trade);
    }
  }  // input file get closed here

  {  // output trade statistics per symbol
    std::ofstream out(outfile);
    if (!out) {
      std::cerr << "Couldn't open file " << outfile << std::endl;
      return 1;
    }

    out.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    std::string symbol(3, 'a');
    for (int32_t i = 0; i < N; ++i) {
      if (tradeStats[i].getTotalVolume() > 0) {
        Symbol::getSymbol(i, symbol);
        out << symbol << ',' << tradeStats[i] << '\n';
      }
    }
  }  // output file get flushed and closed here

  return 0;
}
