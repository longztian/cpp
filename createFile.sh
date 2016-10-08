#!/bin/bash

ROOTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

if [[ "$#" -ne 1 ]]; then
  echo "Usage: $0 <name>"
  exit 1
fi

tmp=$( pwd )/$1
name=$( basename $tmp )
path=$( cd "$( dirname "$tmp" )" && pwd )/$name

GUARD=$( echo ${path#$ROOTDIR/} | tr 'a-z' 'A-Z' | sed 's/[^0-9A-Z]/_/g' )_HPP_
cat > $path.hpp <<EOF
#ifndef ${GUARD}
#define ${GUARD}

void $name();

#endif  // ${GUARD}
EOF

cat > $path.cpp <<EOF
#include "$name.hpp"

void $name() {
}
EOF

cat > $path.test.cpp <<EOF
#include "catch.hpp"
#include "$name.hpp"

TEST_CASE("$name test", "[$name]") {
  $name()
  REQUIRE(1 == 1);
}
EOF
