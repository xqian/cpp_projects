// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "./Intersect_sorted_arrays1.h"
#include "./Intersect_sorted_arrays2.h"
#include "./Intersect_sorted_arrays3.h"

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

void check_ans(const vector<int> &a, const vector<int> &b,
               const vector<int> &c) {
  cout << a.size() << ' ' << b.size() << ' ' << c.size() << endl;
  assert(a.size() == b.size());
  assert(b.size() == c.size());
  for (int i = 0; i < a.size(); ++i) {
    assert(a[i] == b[i]);
    assert(b[i] == c[i]);
  }
}

int main(int argc, char *argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    int n, m;
    vector<int> A, B;
    if (argc == 3) {
      n = atoi(argv[1]), m = atoi(argv[2]);
    } else {
      uniform_int_distribution<int> dis(1, 10000);
      n = dis(gen), m = dis(gen);
    }
    uniform_int_distribution<int> n_dis(0, n - 1);
    for (int i = 0; i < n; ++i) {
      A.emplace_back(n_dis(gen));
    }
    uniform_int_distribution<int> m_dis(0, m - 1);
    for (int j = 0; j < m; ++j) {
      B.emplace_back(m_dis(gen));
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> res1 = intersect_arrs1(A, B);
    vector<int> res2 = intersect_arrs2(A, B);
    vector<int> res3 = intersect_arrs3(A, B);
    check_ans(res1, res2, res3);
  }
  return 0;
}
