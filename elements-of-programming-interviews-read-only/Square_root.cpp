// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <cmath>
#include <iostream>
#include <limits>
#include <random>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::numeric_limits;
using std::random_device;
using std::uniform_real_distribution;

// @include
// 0 means equal, -1 means smaller, and 1 means larger.
int compare(double a, double b) {
  // Use normalization for precision problem.
  double diff = (a - b) / b;
  return diff < -numeric_limits<double>::epsilon()
             ? -1
             : diff > numeric_limits<double>::epsilon();
}

double square_root(double x) {
  // Decide the search range according to x.
  double l, r;
  if (compare(x, 1.0) < 0) {  // x < 1.0.
    l = x, r = 1.0;
  } else {  // x >= 1.0.
    l = 1.0, r = x;
  }

  // Keep searching if l < r.
  while (compare(l, r) == -1) {
    double m = l + 0.5 * (r - l);
    double square_m = m * m;
    if (compare(square_m, x) == 0) {
      return m;
    } else if (compare(square_m, x) == 1) {
      r = m;
    } else {
      l = m;
    }
  }
  return l;
}
// @exclude

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 100000; ++times) {
    double x;
    if (argc == 2) {
      x = atof(argv[1]);
    } else {
      uniform_real_distribution<int> dis(0.0, 100000000.0);
      x = dis(gen);
    }
    double res[2];
    cout << "x is " << x << endl;
    cout << (res[0] = square_root(x)) << ' ' << (res[1] = sqrt(x)) << endl;
    assert(compare(res[0], res[1]) == 0);
  }
  return 0;
}
