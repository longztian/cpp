#include <algorithm>
#include "zeroMatrix.hpp"

using row_t = std::vector<int>;
using matrix_t = std::vector<row_t>;

void zeroMatrix(matrix_t& m) {
  if (m.empty()) return;

  // validate matrix shape
  const auto nCol = m.front().size();
  auto c = std::count_if(m.cbegin(), m.cend(),
                         [nCol](const row_t& r){ return r.size() != nCol; });
  if (c > 0) return;

  // scan for zeros
  const auto nRow = m.size();
  std::vector<bool> rowZero(nRow, false), colZero(nCol, false);

  for (size_t i = 0; i < nRow; ++i) {
    for (size_t j = 0; j < nCol; ++j) {
      if (m[i][j] == 0) {
        rowZero[i] = true;
        colZero[j] = true;
      }
    }
  }

  for (size_t i = 0; i < nRow; ++i) {
    if (rowZero[i]) {
      std::fill(m[i].begin(), m[i].end(), 0);
    } else {
      for (size_t j = 0; j < nCol; ++j) {
        if (colZero[j]) m[i][j] = 0;
      }
    }
  }
}
