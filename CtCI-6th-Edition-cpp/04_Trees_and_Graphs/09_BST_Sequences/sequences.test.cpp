#include "catch.hpp"
#include "sequences.hpp"

namespace BT = BinaryTreeUnique;

TEST_CASE("sequences test", "[sequences]") {
  auto tree = BT::create("[2,1,null,null,3]");
  REQUIRE(sequences(tree) == arrays({{2, 1, 3}, {2, 3, 1}}));
}
