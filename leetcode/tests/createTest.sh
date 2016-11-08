#!/bin/bash

if [[ "$#" -ne 1 ]]; then
  echo "Usage: $0 <name>"
  exit 1
fi

src=$1
name=$( basename -s .cpp $src )

GUARD=LEETCODE_TESTS_$( echo $name | tr 'a-z' 'A-Z' | sed 's/[^0-9A-Z]/_/g' )_HPP_
cat > $name.hpp <<EOF
#ifndef ${GUARD}
#define ${GUARD}

#include "COMMON.hpp"

EOF

cat >> $name.hpp < $src

cat >> $name.hpp <<EOF

#endif  // ${GUARD}
EOF

cat > $name.test.cpp <<EOF
#include "catch.hpp"
#include "$name.hpp"

TEST_CASE("test $name", "[$name]") {
  Solution s;

  REQUIRE(1 == 1);
}
EOF
