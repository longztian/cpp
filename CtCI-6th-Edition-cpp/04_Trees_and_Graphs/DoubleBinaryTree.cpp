#include <vector>
#include <cstddef>
#include "DoubleBinaryTree.hpp"

void myToString(const p_node_t& root, std::string& tree) {
  if (root == nullptr) {
    tree.append("null,");
    return;
  }

  tree.append(std::to_string(root->data) + ",");
  myToString(root->left, tree);
  myToString(root->right, tree);
}

namespace DoubleBinaryTree {

p_node_t create(const std::string& tree) {
  if (tree.size() < 3) return p_node_t(nullptr);
  if (tree.front() != '[' || tree.back() != ']') return p_node_t(nullptr);

  p_node_t root;
  p_node_t p = nullptr;
  std::vector<p_node_t> stack;

  std::size_t begin = 1, end = tree.find_first_of(',', begin);
  while (begin < tree.size()) {
    // last token
    if (end == std::string::npos) end = tree.find_first_of(']', begin);

    auto token = tree.substr(begin, end - begin);
    if (token == "null") {
      // branch terminitor
      if (stack.empty()) break;

      p = stack.back();
      stack.pop_back();
    } else {
      // new node
      auto v = std::stoi(token);
      if (p == nullptr) {
        if (stack.empty()) {
          root = std::make_shared<DoubleBinaryTreeNode>(v);
          stack.push_back(root);
        } else {
          stack.back()->left = std::make_shared<DoubleBinaryTreeNode>(v);
          stack.back()->left->parent = stack.back();
          stack.push_back(stack.back()->left);
        }
      } else {
        p->right = std::make_shared<DoubleBinaryTreeNode>(v);
        p->right->parent = p;
        stack.push_back(p->right);
        p = nullptr;
      }
    }

    begin = end + 1;
    end = tree.find_first_of(',', begin);
  }

  return root;
}

std::string toString(const p_node_t& root) {
  std::string tree("[");
  myToString(root, tree);
  tree.back() = ']';
  return tree;
}

bool equal(const p_node_t& t1, const p_node_t& t2) {
  if (t1 == nullptr && t2 == nullptr) return true;
  if (t1 == nullptr || t2 == nullptr) return false;

  return t1->data == t2->data &&
         equal(t1->left, t2->left) &&
         equal(t1->right, t2->right);
}

}  // namespace DoubleBinaryTree
