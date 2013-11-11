// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <list>
#include <memory>

#include "./BST_parent_prototype.h"

using std::list;
using std::unique_ptr;

template <typename T>
BinarySearchTree<T>* find_successor_BST(BinarySearchTree<T>* n) {
  if (n->right) {
    // Find the smallest element in n's right subtree.
    n = n->right.get();
    while (n->left) {
      n = n->left.get();
    }
    return n;
  }

  // Find the first parent which is larger than n.
  while (n->parent && n->parent->right.get() == n) {
    n = n->parent;
  }
  // Return nullptr means n is the largest in this BST.
  return n->parent ? n->parent : nullptr;
}

// @include
template <typename T>
BinarySearchTree<T>* find_first_larger_equal_k(
    const unique_ptr<BinarySearchTree<T>>& r,
    const T& k) {
  if (!r) {
    return nullptr;
  } else if (r->data >= k) {
    // Recursively search the left subtree for first one >= k.
    auto n = find_first_larger_equal_k(r->left, k);
    return n ? n : r.get();
  }
  // r->data < k so search the right subtree.
  return find_first_larger_equal_k(r->right, k);
}

template <typename T>
list<BinarySearchTree<T>*> range_query_on_BST(
    const unique_ptr<BinarySearchTree<T>>& n,
    const T& L,
    const T& U) {
  list<BinarySearchTree<T>*> res;
  for (auto* it = find_first_larger_equal_k(n, L); it && it->data <= U;
       it = find_successor_BST(it)) {
    res.emplace_back(it);
  }
  return res;
}
// @exclude

int main(int argc, char* argv[]) {
  //      3
  //    2   5
  //  1    4  6
  auto root = unique_ptr<BinarySearchTree<int>>(new BinarySearchTree<int>{3});
  root->parent = nullptr;
  root->left = unique_ptr<BinarySearchTree<int>>(new BinarySearchTree<int>{2});
  root->left->parent = root.get();
  root->left->left =
      unique_ptr<BinarySearchTree<int>>(new BinarySearchTree<int>{1});
  root->left->left->parent = root->left.get();
  root->right =
      unique_ptr<BinarySearchTree<int>>(new BinarySearchTree<int>{5});
  root->right->parent = root.get();
  root->right->left =
      unique_ptr<BinarySearchTree<int>>(new BinarySearchTree<int>{4});
  root->right->left->parent = root->right.get();
  root->right->right =
      unique_ptr<BinarySearchTree<int>>(new BinarySearchTree<int>{6});
  root->right->right->parent = root->right.get();
  list<BinarySearchTree<int>*> res = range_query_on_BST<int>(root, 2, 5);
  assert(res.size() == 4);
  for (const auto* l : res) {
    assert(l->data >= 2 && l->data <= 5);
  }
  res = range_query_on_BST(root, -1, 0);
  assert(res.empty());
  res = range_query_on_BST(root, 10, 25);
  assert(res.empty());
  res = range_query_on_BST(root, -10, 30);
  assert(res.size() == 6);
  for (const auto* l : res) {
    assert(l->data >= 1 && l->data <= 6);
  }
  return 0;
}
