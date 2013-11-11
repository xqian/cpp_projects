// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <iostream>
#include <random>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

// @include
// Return the number of fail trails.
int simulate_biased_coin(int n, int trails) {
  default_random_engine gen((random_device())());  // random num generator.
  // Generate random double in [0.0, 1.0].
  uniform_real_distribution<double> dis(0.0, 1.0);
  const double kBias = 0.4;
  int fails = 0;
  for (int i = 0; i < trails; ++i) {
    int biased_num = 0;
    for (int j = 0; j < n; ++j) {
      biased_num += (dis(gen) >= kBias);
    }

    if (biased_num < (n >> 1)) {
      ++fails;
    }
  }
  return fails;
}
// @exclude

int main(int argc, char* argv[]) {
  int n, trails;
  default_random_engine gen((random_device())());
  if (argc == 3) {
    n = atoi(argv[1]);
    trails = atoi(argv[2]);
  } else {
    uniform_int_distribution<int> dis(1, 1000);
    n = dis(gen);
    trails = dis(gen);
  }
  int fails = simulate_biased_coin(n, trails);
  cout << "fails = " << fails << endl;
  cout << "ratio = " << static_cast<double>(fails) / trails << endl;
  return 0;
}
