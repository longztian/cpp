```sh
# leetcode testing framework files
ikki@dt:~/github/cpp/leetcode/tests$ ls -lt
total 12
-rw-r--r-- 1 ikki ikki  226 Nov  8 08:01 COMMON.hpp
-rwxr-xr-x 1 ikki ikki  507 Nov  8 08:01 createTest.sh
-rw-r--r-- 1 ikki ikki 1272 Nov  8 07:20 Makefile

# create a test
ikki@dt:~/github/cpp/leetcode/tests$ ./createTest.sh ../127_Word_Ladder.cpp 

# test files created
ikki@dt:~/github/cpp/leetcode/tests$ ls -lt 127_Word_Ladder*
total 20
-rw-r--r-- 1 ikki ikki 2075 Nov  8 08:03 127_Word_Ladder.hpp
-rw-r--r-- 1 ikki ikki  146 Nov  8 08:03 127_Word_Ladder.test.cpp

# the default test case
ikki@dt:~/github/cpp/leetcode/tests$ cat 127_Word_Ladder.test.cpp
#include "catch.hpp"
#include "127_Word_Ladder.hpp"

TEST_CASE("test 127_Word_Ladder", "[127_Word_Ladder]") {
  Solution s;

  REQUIRE(1 == 1);
}

# build the default test
ikki@dt:~/github/cpp/leetcode/tests$ make
g++ -c  -g -fPIC -std=c++14 -I/home/ikki/github/cpp/include -o 127_Word_Ladder.test.o 127_Word_Ladder.test.cpp
g++ -c -g -fPIC -std=c++14 -I/home/ikki/github/cpp/include -o /tmp/test.o /tmp/test.cpp
g++ -MM -g -fPIC -std=c++14 -I/home/ikki/github/cpp/include 127_Word_Ladder.test.cpp > .dep/127_Word_Ladder.test.d
g++ -g -fPIC -std=c++14 -I/home/ikki/github/cpp/include  -o /tmp/test  ./127_Word_Ladder.test.o /tmp/test.o

# run test
ikki@dt:~/github/cpp/leetcode/tests$ make test
/tmp/test
===============================================================================
All tests passed (1 assertion in 1 test case)

# modify test case by adding new assertions
ikki@dt:~/github/cpp/leetcode/tests$ cat 127_Word_Ladder.test.cpp
#include "catch.hpp"
#include "127_Word_Ladder.hpp"

TEST_CASE("test 127_Word_Ladder", "[127_Word_Ladder]") {
  Solution s;
  unordered_set<string> list;

  list = unordered_set<string>({"a", "b", "c"});
  REQUIRE(2 == s.ladderLength("a", "c", list));

  list = unordered_set<string>({"hot", "dog"});
  REQUIRE(0 == s.ladderLength("hot", "dog", list));

  list = unordered_set<string>({"hot", "dog", "dot"});
  REQUIRE(3 == s.ladderLength("hot", "dog", list));

  list = unordered_set<string>({"hot", "dot", "dog", "lot", "log"});
  REQUIRE(5 == s.ladderLength("hit", "cog", list));
}

# build test again
ikki@dt:~/github/cpp/leetcode/tests$ make
g++ -c  -g -fPIC -std=c++14 -I/home/ikki/github/cpp/include -o 127_Word_Ladder.test.o 127_Word_Ladder.test.cpp
g++ -MM -g -fPIC -std=c++14 -I/home/ikki/github/cpp/include 127_Word_Ladder.test.cpp > .dep/127_Word_Ladder.test.d
g++ -g -fPIC -std=c++14 -I/home/ikki/github/cpp/include  -o /tmp/test  ./127_Word_Ladder.test.o /tmp/test.o

# run test again
ikki@dt:~/github/cpp/leetcode/tests$ make test
/tmp/test
===============================================================================
All tests passed (4 assertions in 1 test case)

# clean build files
ikki@dt:~/github/cpp/leetcode/tests$ make clean
rm -rf /tmp/test  ./127_Word_Ladder.test.o .dep /tmp/test.*
