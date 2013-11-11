// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

using std::boolalpha;
using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

// @include
bool has_2_sum(const vector<int>& A, int t) {
  int j = 0, k = A.size() - 1;

  while (j <= k) {
    if (A[j] + A[k] == t) {
      return true;
    } else if (A[j] + A[k] < t) {
      ++j;
    } else {  // A[j] + A[k] > t.
      --k;
    }
  }
  return false;
}

bool has_3_sum(vector<int> A, int t) {
  sort(A.begin(), A.end());

  for (const int& a : A) {
    // Find if the sum of two numbers in A equals to t - a.
    if (has_2_sum(A, t - a)) {
      return true;
    }
  }
  return false;
}
// @exclude

// n^3 solution
bool check_ans(const vector<int>& A, int t) {
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < A.size(); ++j) {
      for (int k = 0; k < A.size(); ++k) {
        if (A[i] + A[j] + A[k] == t) {
          return true;
        }
      }
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    int n, T;
    if (argc == 2) {
      n = atoi(argv[1]);
      uniform_int_distribution<int> dis(0, n - 1);
      T = dis(gen);
    } else {
      uniform_int_distribution<int> dis(1, 10000);
      n = dis(gen);
      uniform_int_distribution<int> T_dis(0, n - 1);
      T = T_dis(gen);
    }
    vector<int> A;
    for (size_t i = 0; i < n; ++i) {
      uniform_int_distribution<int> dis(-100000, 100000);
      A.emplace_back(dis(gen));
    }
    cout << boolalpha << has_3_sum(A, T) << endl;
    assert(check_ans(A, T) == has_3_sum(A, T));
  }
  return 0;
}
