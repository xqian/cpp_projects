// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// @include
string decoding(const string &s) {
  int count = 0;
  string ret;
  for (const char &c : s) {
    if (isdigit(c)) {
      count = count * 10 + c - '0';
    } else {  // isalpha.
      ret.append(count, c);
      count = 0;
    }
  }
  return ret;
}

string encoding(const string &s) {
  int count = 1;
  stringstream ss;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i - 1]) {
      ++count;
    } else {
      ss << count << s[i - 1];
      count = 1;
    }
  }
  ss << count << s.back();
  return ss.str();
}
// @exclude

int main(int argc, char *argv[]) {
  if (argc == 3) {
    cout << encoding(argv[1]) << ' ' << decoding(argv[2]) << endl;
  }
  assert(string("4a1b3c2a") == encoding("aaaabcccaa"));
  assert(string("eeeffffee") == decoding("3e4f2e"));
  assert(string("aaaaaaaaaaffffee") == decoding("10a4f2e"));
  return 0;
}
