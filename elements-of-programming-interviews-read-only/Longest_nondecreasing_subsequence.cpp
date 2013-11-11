// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "./Longest_nondecreasing_subsequence_n2.h"
#include "./Longest_nondecreasing_subsequence_nlogn.h"

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

int main(int argc, char *argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    int n;
    vector<int> A;
    if (argc == 2) {
      n = atoi(argv[1]);
    } else {
      uniform_int_distribution<int> dis(1, 10000);
      n = dis(gen);
    }
    for (int i = 0; i < n; ++i) {
      uniform_int_distribution<int> dis(0, 99999999);
      A.emplace_back(dis(gen));
    }
    /*
    for (int i = 0; i < A.size(); ++i) {
      cout << A[i] << ' ';
    }
    cout << endl;
    */
    cout << "n = " << n << endl;
    int ret_length = LNS_nlogn::longest_nondecreasing_subsequence(A);
    vector<int> output = LNS_n2::longest_nondecreasing_subsequence(A);
    assert(ret_length == output.size());
  }
  return 0;
}
