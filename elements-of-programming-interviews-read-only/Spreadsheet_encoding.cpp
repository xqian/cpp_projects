// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <iostream>
#include <random>
#include <string>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::string;
using std::uniform_int_distribution;

string rand_string(int len) {
  default_random_engine gen((random_device())());
  string ret;
  uniform_int_distribution<int> dis('A', 'Z');
  while (len--) {
    ret.push_back(dis(gen));
  }
  return ret;
}

// @include
int ssDecodeColID(const string& col) {
  int ret = 0;
  for (const char& c : col) {
    ret = ret * 26 + c - 'A' + 1;
  }
  return ret;
}
// @exclude

void simple_test() {
  assert(1 == ssDecodeColID("A"));
  assert(27 == ssDecodeColID("AA"));
}

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  if (argc == 2) {
    cout << argv[1] << " " << ssDecodeColID(argv[1]) << endl;
  } else {
    uniform_int_distribution<int> len_dis(1, 5);
    string s(rand_string(len_dis(gen)));
    cout << s << " " << ssDecodeColID(s) << endl;
  }
  return 0;
}
