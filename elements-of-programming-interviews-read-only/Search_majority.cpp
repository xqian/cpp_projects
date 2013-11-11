// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::istringstream;
using std::random_device;
using std::string;
using std::uniform_int_distribution;
using std::vector;

// @include
string majority_search(istringstream* sin) {
  string candidate, buf;
  int count = 0;
  while (*sin >> buf) {
    if (count == 0) {
      candidate = buf;
      count = 1;
    } else if (candidate == buf) {
      ++count;
    } else {
      --count;
    }
  }
  return candidate;
}
// @exclude

string rand_string(int len) {
  default_random_engine gen((random_device())());
  string ret;
  while (len--) {
    uniform_int_distribution<int> dis('a', 'z');
    ret += dis(gen);
  }
  return ret;
}

void check_ans(vector<string>& stream, const string& ans) {
  sort(stream.begin(), stream.end());
  int count = 1;
  bool find = false;
  for (int i = 1; i < stream.size(); ++i) {
    if (stream[i].compare(stream[i - 1])) {
      if (count * 2 >= stream.size()) {
        assert(ans.compare(stream[i - 1]) == 0);
        find = true;
      }
      count = 1;
    } else {
      ++count;
    }
  }
  if (count * 2 >= stream.size()) {
    assert(ans.compare(stream.back()) == 0);
    find = true;
  }
  assert(find == true);
}

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 10000; ++times) {
    int n;
    vector<string> stream;
    if (argc == 2) {
      n = atoi(argv[1]);
    } else {
      uniform_int_distribution<int> n_dis(1, 1000);
      n = n_dis(gen);
    }
    for (int i = 0; i < n; ++i) {
      uniform_int_distribution<int> dis(1, 5);
      stream.emplace_back(rand_string(dis(gen)));
    }
    // generate the majority
    for (int i = 0; i < n; ++i) {
      stream.emplace_back(stream.back());
    }
    string s;
    for (int i = 0; i < stream.size(); ++i) {
      s += stream[i];
      s += ' ';
    }
    istringstream sin(s);
    string ret(majority_search(&sin));
    cout << ret << endl;
    check_ans(stream, ret);
  }
  return 0;
}
