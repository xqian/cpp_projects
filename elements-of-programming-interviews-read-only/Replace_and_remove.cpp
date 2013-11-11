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

// @include
string replace_and_remove(string s) {
  // Removes "b" and count the number of "a".
  int write_idx = 0, a_count = 0;
  for (const char &c : s) {
    if (c != 'b') {
      s[write_idx++] = c;
    }
    if (c == 'a') {
      ++a_count;
    }
  }

  // Allocates space according to the number of "a".
  s.resize(write_idx + a_count);
  // Replace "a" with "dd".
  int cur_idx = write_idx - 1;
  write_idx = s.size() - 1;
  while (cur_idx >= 0) {
    if (s[cur_idx] == 'a') {
      s[write_idx--] = 'd';
      s[write_idx--] = 'd';
    } else {
      s[write_idx--] = s[cur_idx];
    }
    --cur_idx;
  }
  return s;
}
// @exclude

string rand_string(int len) {
  default_random_engine gen((random_device())());
  string ret;
  while (len--) {
    uniform_int_distribution<char> dis('a', 'd');
    ret += dis(gen);
  }
  return ret;
}

void check_ans(const string &s, const string &ans) {
  string temp;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'a') {
      temp += 'd', temp += 'd';
    } else if (s[i] != 'b') {
      temp += s[i];
    }
  }
  assert(ans.compare(temp) == 0);
}

int main(int argc, char *argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    string s;
    if (argc == 2) {
      s = argv[1];
    } else {
      uniform_int_distribution<int> dis(1, 1000);
      s = rand_string(dis(gen));
    }
    cout << s << endl << endl;
    string ans = replace_and_remove(s);
    cout << ans << endl;
    check_ans(s, ans);
  }
  return 0;
}
