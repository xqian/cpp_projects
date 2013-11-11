// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::swap;
using std::uniform_int_distribution;
using std::vector;

// @include
vector<int> next_permutation(vector<int> p) {
  int k = p.size() - 2;
  while (k >= 0 && p[k] >= p[k + 1]) {
    --k;
  }
  if (k == -1) {
    return {};  // p is the last permutation.
  }

  int l;
  for (int i = k + 1; i < p.size(); ++i) {
    if (p[i] > p[k]) {
      l = i;
    } else {
      break;
    }
  }
  swap(p[k], p[l]);

  // Produce the lexicographically minimal permutation.
  reverse(p.begin() + k + 1, p.end());
  return p;
}
// @exclude

int main(int argc, char *argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    vector<int> p;
    if (argc > 2) {
      for (size_t i = 1; i < argc; ++i) {
        p.emplace_back(atoi(argv[i]));
      }
    } else {
      uniform_int_distribution<int> dis(1, 100);
      int n = (argc == 2 ? atoi(argv[1]) : dis(gen));
      uniform_int_distribution<int> n_dis(0, n - 1);
      for (size_t i = 0; i < n; ++i) {
        p.emplace_back(n_dis(gen));
      }
    }

    vector<int> ans(next_permutation(p));
    next_permutation(p.begin(), p.end());
    assert(equal(ans.cbegin(), ans.cend(), p.cbegin()));
  }
  return 0;
}
