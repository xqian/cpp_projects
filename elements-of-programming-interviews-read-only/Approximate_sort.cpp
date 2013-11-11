// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <functional>
#include <iostream>
#include <queue>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::greater;
using std::istringstream;
using std::priority_queue;
using std::random_device;
using std::string;
using std::stringstream;
using std::uniform_int_distribution;
using std::vector;

// @include
void approximate_sort(istringstream* sin, int k) {
  priority_queue<int, vector<int>, greater<int>> min_heap;
  // Firstly push k elements into min_heap.
  int x;
  for (int i = 0; i < k && *sin >> x; ++i) {
    min_heap.push(x);
  }

  // Extract the minimum one for every incoming element.
  while (*sin >> x) {
    min_heap.push(x);
    cout << min_heap.top() << endl;
    min_heap.pop();
  }

  // Extract the remaining elements in min_heap.
  while (!min_heap.empty()) {
    cout << min_heap.top() << endl;
    min_heap.pop();
  }
}
// @exclude

// It should print 1, 2, 3, 4, 5, 6, 7, ,8, 9.
void simple_test() {
  vector<int> A = {2, 1, 5, 4, 3, 9, 8, 7, 6};
  stringstream ss;
  for (const int& a : A) {
    ss << a << ' ';
  }
  istringstream sin(ss.str());
  approximate_sort(&sin, 3);
}

int main(int argc, char* argv[]) {
  simple_test();
  default_random_engine gen((random_device())());
  int n, k;
  if (argc == 2) {
    n = atoi(argv[1]);
    uniform_int_distribution<int> dis(1, n);
    k = dis(gen);
  } else if (argc == 3) {
    n = atoi(argv[1]);
    k = atoi(argv[2]);
  } else {
    uniform_int_distribution<int> n_dis(1, 100000);
    n = n_dis(gen);
    uniform_int_distribution<int> k_dis(1, n);
    k = k_dis(gen);
  }
  cout << "n = " << n << " k = " << k << endl;
  vector<int> A;
  uniform_int_distribution<int> dis(1, 999999);
  for (int i = 0; i < n; ++i) {
    A.push_back(dis(gen));
  }
  stringstream ss;
  for (const int& a : A) {
    ss << a << ' ';
  }
  istringstream sin(ss.str());
  approximate_sort(&sin, n - 1);
  return 0;
}
