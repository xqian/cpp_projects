// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "./Rotate_array.h"
#include "./Rotate_array_permutation.h"

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

vector<int> rand_vector(int len) {
  default_random_engine gen((random_device())());
  vector<int> ret;
  uniform_int_distribution<int> dis(0, len);
  while (len--) {
    ret.emplace_back(dis(gen));
  }
  return ret;
}

void check_answer(const vector<int> &A, int i, const vector<int> &rotated) {
  assert(A.size() == rotated.size());
  for (size_t idx = 0; idx < A.size(); ++idx) {
    assert(rotated[(idx + i) % rotated.size()] == A[idx]);
  }
}

int main(int argc, char *argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    int len;
    if (argc == 2) {
      len = atoi(argv[1]);
    } else {
      uniform_int_distribution<int> dis(1, 10000);
      len = dis(gen);
    }
    vector<int> A(rand_vector(len));
    uniform_int_distribution<int> dis(0, len - 1);
    int i = dis(gen);
    vector<int> B(A);
    rotate_array1::rotate_array(&B, i);
    check_answer(A, i, B);
    vector<int> C(A);
    rotate_array2::rotate_array(&C, i);
    check_answer(A, i, C);
  }
  return 0;
}
