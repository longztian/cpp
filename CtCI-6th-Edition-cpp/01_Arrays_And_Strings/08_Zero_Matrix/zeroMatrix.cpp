#include <algorithm>
#include "zeroMatrix.hpp"

using row_t = std::vector<int>;
using matrix_t = std::vector<row_t>;

void zeroMatrix(matrix_t& m) {
  if (m.empty()) return;

  // validate matrix shape
  const auto n = m.front().size();
  auto c = std::count_if(m.cbegin(), m.cend(), [n](const row_t& r){
    return r.size() != n;
  });
  if (c > 0) return;

  // scan for zeros
  std::vector<bool> rowZero(m.size(), false), colZero(n, false);
  for (auto i = 0; i < m.size(); ++i) {
    for (auto j = 0; j < m[i].size(); ++j) {
      if (m[i][j] == 0) {
        rowZero[i] = true;
        colZero[j] = true;
      }
    }
  }

  for (auto i = 0; i < m.size(); ++i) {
    if (rowZero[i]) {
      std::fill(m[i].begin(), m[i].end(), 0);
    } else {
      for (auto j = 0; j < n; ++j) {
        if (colZero[j]) m[i][j] = 0;
      }
    }
  }
}
