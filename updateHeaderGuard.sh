#!/bin/bash

ROOTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

if [[ "$#" -ne 1 ]]; then
  echo "Usage: $0 <name>"
  exit 1
fi

tmp=$( pwd )/$1
name=$( basename -s .hpp $tmp )
path=$( cd "$( dirname "$tmp" )" && pwd )/$name

GUARD=$( echo ${path#$ROOTDIR/} | tr 'a-z' 'A-Z' | sed 's/[^0-9A-Z]/_/g' )_HPP_

tmp=/tmp/$GUARD.tmp
echo "#ifndef $GUARD" > $tmp
echo "#define $GUARD" >> $tmp
head -n -1 $path.hpp | tail -n +3 >> $tmp
echo "#endif  // $GUARD" >> $tmp

mv $tmp $path.hpp
