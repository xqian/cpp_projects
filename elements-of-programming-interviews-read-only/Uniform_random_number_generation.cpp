// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <cmath>
#include <iostream>
#include <random>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;

int zero_one_random() {
  default_random_engine gen((random_device())());
  uniform_int_distribution<int> dis(0, 1);
  return dis(gen);
}

// @include
int uniform_random_a_b(int a, int b) {
  int l = b - a + 1, res;
  do {
    res = 0;
    for (int i = 0; (1 << i) < l; ++i) {
      // zero_one_random() is the system-provided random number generator.
      res = (res << 1) | zero_one_random();
    }
  } while (res >= l);
  return res + a;
}
// @exclude

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    int a, b;
    if (argc == 3) {
      a = atoi(argv[1]), b = atoi(argv[2]);
    } else {
      uniform_int_distribution<int> a_dis(0, 99);
      a = a_dis(gen);
      uniform_int_distribution<int> b_dis(a + 1, a + 100);
      b = b_dis(gen);
    }
    int x = uniform_random_a_b(a, b);
    cout << "a = " << a << " b = " << b << endl;
    cout << "random result = " << x << endl;
    assert(x >= a && x <= b);
  }
  return 0;
}
