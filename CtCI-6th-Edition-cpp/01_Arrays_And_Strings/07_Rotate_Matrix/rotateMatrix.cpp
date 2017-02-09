#include <algorithm>
#include <utility>
#include "rotateMatrix.hpp"

// type alias
using row_t = std::vector<int>;
using matrix_t = std::vector<row_t>;

void rotateMatrix(matrix_t& m) {
  if (m.empty()) return;

  // validate matrix shape
  auto n = m.size();
  auto i = std::find_if(m.cbegin(), m.cend(), [n](const row_t& r){
    return r.size() != n;
  });
  if (i != m.cend()) return;

  // 1. copy: row[i][j] = column[j][n-i-1]
  // matrix_t rotate(n, std::vector<int>(n));
  // for (auto i = 0; i < n; ++i) {
  //   for (auto j = 0; j < n; ++j) {
  //     rotate[j][n-i-1] = m[i][j];
  //   }
  // }

  // m = rotate;
  //
  // 2. inplace
  for (row_t& r : m) {
    std::swap_ranges(r.begin(), r.begin() + n / 2, r.rbegin());
  }
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n-i-1; ++j) {
      std::swap(m[i][j], m[n-j-1][n-i-1]);
    }
  }
}
