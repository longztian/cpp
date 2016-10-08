#include "catch.hpp"
#include "firstCommonAncestor.hpp"

namespace BT = BinaryTreeShared;

TEST_CASE("firstCommonAncestor test", "[firstCommonAncestor]") {
  auto root = BT::create("[]");
  auto n1 = root, n2 = root;
  REQUIRE(firstCommonAncestor(root, n1, n2) == nullptr);

  root = BT::create("[1,2,3,4,null,null,5,null,null,6,7,null,null,8,null,null,9,10,null,11]");
  n1 = root->left->left->left;
  n2 = root->left->left->right;
  REQUIRE(n1->data == 4);
  REQUIRE(n2->data == 5);
  REQUIRE(firstCommonAncestor(root, n1, n2) == root->left->left);

  n2 = root->left->right->left;
  REQUIRE(n2->data == 7);
  REQUIRE(firstCommonAncestor(root, n1, n2) == root->left);

  n2 = root->right->left->right;
  REQUIRE(n2->data == 11);
  REQUIRE(firstCommonAncestor(root, n1, n2) == root);

  n2 = root->left->left;
  REQUIRE(n2->data == 3);
  REQUIRE(firstCommonAncestor(root, n1, n2) == root->left->left);
}
