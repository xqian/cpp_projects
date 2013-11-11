// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <memory>

#include "./BST_prototype.h"

using std::unique_ptr;

// @include
template <typename T>
BinarySearchTree<T>* find_LCA(const unique_ptr<BinarySearchTree<T>>& x,
                              const unique_ptr<BinarySearchTree<T>>& s,
                              const unique_ptr<BinarySearchTree<T>>& b) {
  auto* p = x.get();
  while (p->data < s->data || p->data > b->data) {
    while (p->data < s->data) {
      p = p->right.get();  // LCA must be in p's right child.
    }
    while (p->data > b->data) {
      p = p->left.get();  // LCA must be in p's left child.
    }
  }

  // p->data >= s->data && p->data <= b->data.
  return p;
}
// @exclude

int main(int argc, char* argv[]) {
  //      3
  //    2   5
  //  1    4 6
  unique_ptr<BinarySearchTree<int>> root =
      unique_ptr<BinarySearchTree<int>>(new BinarySearchTree<int>{3});
  root->left = unique_ptr<BinarySearchTree<int>>(new BinarySearchTree<int>{2});
  root->left->left =
      unique_ptr<BinarySearchTree<int>>(new BinarySearchTree<int>{1});
  root->right =
      unique_ptr<BinarySearchTree<int>>(new BinarySearchTree<int>{5});
  root->right->left =
      unique_ptr<BinarySearchTree<int>>(new BinarySearchTree<int>{4});
  root->right->right =
      unique_ptr<BinarySearchTree<int>>(new BinarySearchTree<int>{6});
  assert(3 == find_LCA(root, root->left->left, root->right->left)->data);
  assert(5 == find_LCA(root, root->right->left, root->right->right)->data);
  assert(2 == find_LCA(root, root->left->left, root->left)->data);
  return 0;
}
