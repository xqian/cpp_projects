// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <iostream>
#include <memory>

#include "./Binary_tree_with_parent_prototype.h"

using std::cout;
using std::endl;
using std::unique_ptr;

// @include
template <typename T>
BinaryTree<T>* find_successor(const unique_ptr<BinaryTree<T>>& node) {
  auto* n = node.get();
  if (n->right) {
    // Find the leftmost element in n's right subtree.
    n = n->right.get();
    while (n->left) {
      n = n->left.get();
    }
    return n;
  }

  // Find the first parent whose left child contains n.
  while (n->parent && n->parent->right.get() == n) {
    n = n->parent;
  }
  // Return nullptr means n does not have successor.
  return n->parent;
}
// @exclude

int main(int argc, char* argv[]) {
  //      3
  //    2   5
  //  1    4  6
  auto root = unique_ptr<BinaryTree<int>>(new BinaryTree<int>{3});
  root->parent = nullptr;
  root->left = unique_ptr<BinaryTree<int>>(new BinaryTree<int>{2});
  root->left->parent = root.get();
  root->left->left = unique_ptr<BinaryTree<int>>(new BinaryTree<int>{1});
  root->left->left->parent = root->left.get();
  root->right = unique_ptr<BinaryTree<int>>(new BinaryTree<int>{5});
  root->right->parent = root.get();
  root->right->left = unique_ptr<BinaryTree<int>>(new BinaryTree<int>{4});
  root->right->left->parent = root->right.get();
  root->right->right = unique_ptr<BinaryTree<int>>(new BinaryTree<int>{6});
  root->right->right->parent = root->right.get();
  // should output 6
  auto* node = find_successor(root->right);
  assert(6 == node->data);
  if (node) {
    cout << node->data << endl;
  } else {
    cout << "null" << endl;
  }
  // should output "null"
  node = find_successor(root->right->right);
  assert(!node);
  if (node) {
    cout << node->data << endl;
  } else {
    cout << "null" << endl;
  }
  return 0;
}
