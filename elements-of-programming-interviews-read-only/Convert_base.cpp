// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
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

// @include
string convert_base(const string& s, int b1, int b2) {
  bool neg = s.front() == '-';
  int x = 0;
  for (int i = (neg == true ? 1 : 0); i < s.size(); ++i) {
    x *= b1;
    x += isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10;
  }

  string ans;
  while (x) {
    int r = x % b2;
    ans.push_back(r >= 10 ? 'A' + r - 10 : '0' + r);
    x /= b2;
  }

  if (ans.empty()) {
    ans.push_back('0');
  }
  if (neg) {
    ans.push_back('-');
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
// @exclude

string rand_int_string(int len) {
  default_random_engine gen((random_device())());
  string ret;
  if (len == 0) {
    return {"0"};
  }
  uniform_int_distribution<int> pos_or_neg(0, 1);
  if (pos_or_neg(gen)) {
    ret.push_back('-');
  }
  uniform_int_distribution<int> num_dis('1', '9');
  ret.push_back(num_dis(gen));
  while (--len) {
    uniform_int_distribution<int> dis('0', '9');
    ret.push_back(dis(gen));
  }
  return ret;
}

int main(int argc, char* argv[]) {
  if (argc == 4) {
    string input(argv[1]);
    cout << convert_base(input, atoi(argv[2]), atoi(argv[3])) << endl;
    assert(input ==
           convert_base(convert_base(input, atoi(argv[2]), atoi(argv[3])),
                        atoi(argv[3]),
                        atoi(argv[2])));
  } else {
    default_random_engine gen((random_device())());
    for (int times = 0; times < 100000; ++times) {
      uniform_int_distribution<int> len_dis(1, 9);
      string input = rand_int_string(len_dis(gen));
      uniform_int_distribution<int> base_dis(2, 16);
      int base = base_dis(gen);
      cout << "input is " << input << ", base1 = 10, base2 = " << base
           << ", ans = " << convert_base(input, 10, base) << endl;
      assert(input == convert_base(convert_base(input, 10, base), base, 10));
    }
  }
  return 0;
}
