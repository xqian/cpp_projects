// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

#include "./Permutation_array1.h"
#include "./Permutation_array2.h"

using std::cout;
using std::default_random_engine;
using std::endl;
using std::ostream_iterator;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

int main(int argc, char *argv[]) {
  default_random_engine gen((random_device())());
  int n;
  for (int times = 0; times < 1000; ++times) {
    if (argc == 2) {
      n = atoi(argv[1]);
    } else {
      uniform_int_distribution<int> dis(1, 100);
      n = dis(gen);
    }
    vector<int> A, perm;
    for (int i = 0; i < n; ++i) {
      A.emplace_back(i);
      perm.emplace_back(i);
    }

    // knuth shuffle
    random_shuffle(perm.begin(), perm.end());
    copy(perm.begin(), perm.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> B(A);
    apply_permutation1(&perm, &B);
    copy(B.begin(), B.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    vector<int> C(A);
    apply_permutation2(&perm, &C);
    copy(C.begin(), C.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    // check answer by comparing the two permutations
    assert(equal(B.begin(), B.end(), C.begin()));
    assert(B.size() == C.size());
  }
  return 0;
}
