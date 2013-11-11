// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::string;
using std::uniform_int_distribution;
using std::vector;

// @include
const int kBase = 26, kMod = 997;

int rabin_karp(const string &t, const string &s) {
  if (s.size() > t.size()) {
    return -1;  // s is not a substring of t.
  }

  int t_hash = 0, s_hash = 0;  // hash codes for the substring of t and s.
  int power_s = 1;  // the modulo result of kBase^|s|.
  for (int i = 0; i < s.size(); ++i) {
    power_s = i ? power_s * kBase % kMod : 1;
    t_hash = (t_hash * kBase + t[i]) % kMod;
    s_hash = (s_hash * kBase + s[i]) % kMod;
  }

  for(int i = s.size(); i < t.size(); ++i) {
    // In case of hash collision but two strings are not equal, check the
    // two substrings are actually equal or not.
    if (t_hash == s_hash && !t.compare(i - s.size(), s.size(), s)) {
      return i - s.size();  // find a match.
    }

    // Use rolling hash to compute the new hash code.
    t_hash -= (t[i - s.size()] * power_s) % kMod;
    if (t_hash < 0) {
      t_hash += kMod;
    }
    t_hash = (t_hash * kBase + t[i]) % kMod;
  }

  // Try to match s and t[t.size() - s.size() : t.size() - 1].
  if (t_hash == s_hash && t.compare(t.size() - s.size(), s.size(), s) == 0) {
    return t.size() - s.size();
  }
  return -1;  // s is not a substring of t.
}
// @exclude

int check_answer(const string &t, const string &s) {
  for (int i = 0; i + s.size() - 1 < t.size(); ++i) {
    bool find = true;
    for (int j = 0; j < s.size(); ++j) {
      if (t[i + j] != s[j]) {
        find = false;
        break;
      }
    }
    if (find == true) {
      return i;
    }
  }
  return -1;  // find no matching.
}

string rand_string(int len) {
  default_random_engine gen((random_device())());
  string ret;
  while (len--) {
    uniform_int_distribution<char> dis('a', 'z');
    ret += dis(gen);
  }
  return ret;
}

int main(int argc, char *argv[]) {
  if (argc == 3) {
    string t = argv[1];
    string s = argv[2];
    cout << "t = " << t << endl;
    cout << "s = " << s << endl;
    assert(rabin_karp(t, s) == check_answer(t, s));
  } else {
    default_random_engine gen((random_device())());
    for (int times = 0; times < 10000; ++times) {
      uniform_int_distribution<int> t_dis(1, 1000);
      uniform_int_distribution<int> s_dis(1, 20);
      string t = rand_string(t_dis(gen));
      string s = rand_string(s_dis(gen));
      cout << "t = " << t << endl;
      cout << "s = " << s << endl;
      int ret1 = rabin_karp(t, s);
      int ret2 = check_answer(t, s);
      cout << ret1 << " " << ret2 << endl;
      assert(rabin_karp(t, s) == check_answer(t, s));
    }
  }
  return 0;
}
