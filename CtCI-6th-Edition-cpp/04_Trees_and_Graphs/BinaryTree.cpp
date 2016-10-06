#include <vector>
#include <cstddef>
#include "BinaryTree.hpp"

void myToString(const p_node_t& root, std::string& tree) {
  if (root == nullptr) {
    tree.append("null,");
    return;
  }

  tree.append(std::to_string(root->data) + ",");
  myToString(root->left, tree);
  myToString(root->right, tree);
}

namespace BinaryTree {
  p_node_t create(const std::string& tree) {
    if (tree.size() < 2) return p_node_t(nullptr);
    if (tree.front() != '[' || tree.back() != ']') return p_node_t(nullptr);

    p_node_t root;
    BinaryTreeNode* p = nullptr;
    std::vector<BinaryTreeNode*> stack;

    std::size_t begin = 1, end = tree.find_first_of(',', begin);
    while (begin < tree.size()) {
      // last token
      if (end == std::string::npos) end = tree.find_first_of(']', begin);

      auto token = tree.substr(begin, end - begin);
      if (token == "null") {
        // branch terminitor
        if (stack.empty()) break;

        if (p == nullptr) {
          p = stack.back();
          stack.pop_back();
        }
        else {
          p = nullptr;
        }
      }
      else {
        // new node
        auto v = std::stoi(token);
        if (p == nullptr) {
          if (stack.empty()) {
            root = std::make_unique<BinaryTreeNode>(v);
            stack.push_back(root.get());
          }
          else {
            stack.back()->left = std::make_unique<BinaryTreeNode>(v);
            stack.push_back(stack.back()->left.get());
          }
        }
        else {
          p->right = std::make_unique<BinaryTreeNode>(v);
          stack.push_back(p->right.get());
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
}
