// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <iostream>
#include <cassert>
#include <limits>
#include <list>
#include <queue>
#include <random>
#include <stdexcept>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::invalid_argument;
using std::list;
using std::queue;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

// @include
list<int> get_minimum_expression(int n) {
  if (n == 1) {
    return {1};
  }

  queue<list<int>> exp_lists;
  exp_lists.emplace(1, 1);  // construct the initial list with one node
                            // whose value is 1.
  while (exp_lists.empty() == false) {
    list<int> exp = exp_lists.front();
    exp_lists.pop();
    // Try all possible combinations in list exp.
    for (const int& a : exp) {
      int sum = a + exp.back();
      if (sum > n) {
        break;  // no possible solution.
      }

      list<int> new_exp(exp);
      new_exp.emplace_back(sum);
      if (sum == n) {
        return new_exp;
      }
      exp_lists.emplace(new_exp);
    }
  }
  // @exclude
  throw invalid_argument("unknown error");  // this line should never be called.
  // @include
}
// @exclude

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  int n;
  if (argc == 2) {
    n = atoi(argv[1]);
  } else {
    uniform_int_distribution<int> n_dis(1, 100);
    n = n_dis(gen);
  }
  cout << "n = " << n << endl;
  list<int> min_exp = get_minimum_expression(n);
  for (const int& t : min_exp) {
    cout << t << ' ';
  }
  cout << endl;
  cout << "size = " << min_exp.size() << endl;
  return 0;
}
