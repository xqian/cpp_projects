// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <iostream>
#include <memory>

#include "./Binary_tree_prototype_template.h"

using std::cout;
using std::endl;
using std::unique_ptr;

// @include
template <typename T>
void left_boundary_b_tree(const unique_ptr<BinaryTree<T>>& n,
                          bool is_boundary) {
  if (n) {
    if (is_boundary || (!n->left && !n->right)) {
      cout << n->data << ' ';
    }
    left_boundary_b_tree(n->left, is_boundary);
    left_boundary_b_tree(n->right, is_boundary && !n->left);
  }
}

template <typename T>
void right_boundary_b_tree(const unique_ptr<BinaryTree<T>>& n,
                           bool is_boundary) {
  if (n) {
    right_boundary_b_tree(n->left, is_boundary && !n->right);
    right_boundary_b_tree(n->right, is_boundary);
    if (is_boundary || (!n->left && !n->right)) {
      cout << n->data << ' ';
    }
  }
}

template <typename T>
void exterior_binary_tree(const unique_ptr<BinaryTree<T>>& root) {
  if (root) {
    cout << root->data << ' ';
    left_boundary_b_tree(root->left, true);
    right_boundary_b_tree(root->right, true);
  }
}
// @exclude

int main(int argc, char* argv[]) {
  //      3
  //    2   5
  //  1  0 4 6
  //   -1 -2
  unique_ptr<BinaryTree<int>> root =
      unique_ptr<BinaryTree<int>>(new BinaryTree<int>{3, nullptr, nullptr});
  root->left =
      unique_ptr<BinaryTree<int>>(new BinaryTree<int>{2, nullptr, nullptr});
  root->left->right =
      unique_ptr<BinaryTree<int>>(new BinaryTree<int>{0, nullptr, nullptr});
  root->left->right->left =
      unique_ptr<BinaryTree<int>>(new BinaryTree<int>{-1, nullptr, nullptr});
  root->left->right->right =
      unique_ptr<BinaryTree<int>>(new BinaryTree<int>{-2, nullptr, nullptr});
  root->left->left =
      unique_ptr<BinaryTree<int>>(new BinaryTree<int>{1, nullptr, nullptr});
  root->right =
      unique_ptr<BinaryTree<int>>(new BinaryTree<int>{5, nullptr, nullptr});
  root->right->left =
      unique_ptr<BinaryTree<int>>(new BinaryTree<int>{4, nullptr, nullptr});
  root->right->right =
      unique_ptr<BinaryTree<int>>(new BinaryTree<int>{6, nullptr, nullptr});
  // should output 3 2 1 -1 -2 4 6 5
  exterior_binary_tree(root);
  return 0;
}
