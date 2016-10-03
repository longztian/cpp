#!/bin/bash

if [[ "$#" -ne 1 ]]; then
  echo "Usage: $0 <name>"
  exit 1
fi

name=$1

touch $name.{hpp,cpp,test.cpp}

NAME=`echo $name | tr 'a-z' 'A-Z'`
cat > $name.hpp <<EOF
#ifndef ${NAME}_HPP
#define ${NAME}_HPP

$name();

#endif
EOF

cat > $name.cpp <<EOF
#include "$name.hpp"

$name() {

}
EOF

cat > $name.test.cpp <<EOF
#include "catch.hpp"
#include "$name.hpp"

TEST_CASE("$name test", "[$name]") {
  REQUIRE($name(INPUT) == EXPECT);
}
EOF
