// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#ifndef SOLUTIONS_BINARY_TREE_WITH_PARENT_PROTOTYPE_H_
#define SOLUTIONS_BINARY_TREE_WITH_PARENT_PROTOTYPE_H_

#include <memory>

using std::unique_ptr;

// @include
template <typename T>
struct BinaryTree {
  T data;
  unique_ptr<BinaryTree<T>> left, right;
  BinaryTree<T>* parent;
};
// @exclude
#endif  // SOLUTIONS_BINARY_TREE_WITH_PARENT_PROTOTYPE_H_
