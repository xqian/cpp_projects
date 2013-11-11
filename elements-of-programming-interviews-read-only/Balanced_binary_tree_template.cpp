// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>

#include "./Binary_tree_prototype_template.h"

using std::boolalpha;
using std::cout;
using std::endl;
using std::max;
using std::unique_ptr;

// @include
template <typename T>
int get_height(const unique_ptr<BinaryTree<T>>& n) {
  if (!n) {
    return -1;  // base case.
  }

  int l_height = get_height(n->left);
  if (l_height == -2) {
    return -2;  // left subtree is not balanced.
  }
  int r_height = get_height(n->right);
  if (r_height == -2) {
    return -2;  // right subtree is not balanced.
  }

  if (abs(l_height - r_height) > 1) {
    return -2;  // current node n is not balanced.
  }
  return max(l_height, r_height) + 1;  // return the height.
}

template <typename T>
bool is_balanced_binary_tree(const unique_ptr<BinaryTree<T>>& n) {
  return get_height(n) != -2;
}
// @exclude

int main(int argc, char* argv[]) {
  //  balanced binary tree test
  //      3
  //    2   5
  //  1    4 6
  unique_ptr<BinaryTree<int>> root =
      unique_ptr<BinaryTree<int>>(new BinaryTree<int>());
  root->left = unique_ptr<BinaryTree<int>>(new BinaryTree<int>());
  root->left->left = unique_ptr<BinaryTree<int>>(new BinaryTree<int>());
  root->right = unique_ptr<BinaryTree<int>>(new BinaryTree<int>());
  root->right->left = unique_ptr<BinaryTree<int>>(new BinaryTree<int>());
  root->right->right = unique_ptr<BinaryTree<int>>(new BinaryTree<int>());
  assert(is_balanced_binary_tree<int>(root) == true);
  cout << boolalpha << is_balanced_binary_tree<int>(root) << endl;
  // Non-balanced binary tree test.
  root = unique_ptr<BinaryTree<int>>(new BinaryTree<int>());
  root->left = unique_ptr<BinaryTree<int>>(new BinaryTree<int>());
  root->left->left = unique_ptr<BinaryTree<int>>(new BinaryTree<int>());
  assert(is_balanced_binary_tree<int>(root) == false);
  cout << boolalpha << is_balanced_binary_tree<int>(root) << endl;
  return 0;
}
