#include <cstdint>
#include <vector>
#include <iostream>
#include <fstream>
#include "Symbol.hpp"
#include "Trade.hpp"
#include "Stats.hpp"

const char * const infile = "input.csv";
const char * const outfile = "output.csv";

namespace Symbol = QLTest::Symbol;

using std::int32_t;

const int32_t N = Symbol::BASE3;

int main() {
  std::vector<QLTest::Stats*> stats(N, nullptr);

  {  // load trade records from input file
    std::ifstream in(infile);
    if (!in) {
      std::cerr << "Couldn't open file " << infile << std::endl;
      return 1;
    }

    const int LENGTH = 40;
    char line[LENGTH];
    QLTest::Trade trade;
    while (in.getline(line, LENGTH)) {
      trade.load(line);
      if (stats[trade.symbolId] == nullptr)
        stats[trade.symbolId] = new QLTest::Stats();
      stats[trade.symbolId]->add(trade);
    }

    if (!in.eof()) {
      std::cerr << "Error while reading file " << infile << std::endl;
      return 1;
    }
  }  // input file get closed here

  {  // output trade statistics per symbol
    std::ofstream out(outfile);
    if (!out) {
      std::cerr << "Couldn't open file " << outfile << std::endl;
      return 1;
    }

    const int LENGTH = 4;
    char symbol[LENGTH] = "aaa";
    for (int32_t i = 0; i < N; ++i) {
      if (stats[i]) {
        Symbol::getSymbol(i, symbol);
        out << symbol << ',' << *stats[i] << '\n';
        if (out.fail()) break;
      }
    }

    if (out.good()) out.flush();

    if (out.fail()) {
      std::cerr << "Error while writing file " << outfile << std::endl;
      return 1;
    }
  }  // output file get closed here

  for (auto p : stats) {
    if (p) delete p;
  }

  return 0;
}
