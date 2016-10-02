#!/bin/bash

if [[ "$#" -ne 1 ]]; then
  echo "Usage: $0 <name>"
  exit 1
fi

name=$1

touch $name.{hpp,cpp,test.cpp}
cat > $name.test.cpp <<EOF
#include "catch.hpp"
#include "$name.hpp"

TEST_CASE("DESCRIPTION", "[$name]") {
  REQUIRE($name(ARGS) == EXPECT);
}

EOF
