// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <unordered_set>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::string;
using std::uniform_int_distribution;
using std::unordered_set;
using std::vector;

string rand_string(int len) {
  default_random_engine gen((random_device())());
  string ret;
  while (len--) {
    uniform_int_distribution<int> dis('a', 'z');
    ret += dis(gen);
  }
  return ret;
}

// @include
vector<string> word_breaking(const string& s,
                             const unordered_set<string>& dict) {
  // T[i] stores the length of the last string which composed of s(0, i).
  vector<int> T(s.size(), 0);
  for (int i = 0; i < s.size(); ++i) {
    // Set T[i] if s(0, i) is a valid word.
    if (dict.find(s.substr(0, i + 1)) != dict.cend()) {
      T[i] = i + 1;
    }

    // Set T[i] if T[j] != 0 and s(j + 1, i) is a valid word.
    for (int j = 0; j < i && T[i] == 0; ++j) {
      if (T[j] != 0 && dict.find(s.substr(j + 1, i - j)) != dict.cend()) {
        T[i] = i - j;
      }
    }
  }

  vector<string> ret;
  // s can be assembled by valid words.
  if (T.back()) {
    int idx = s.size() - 1;
    while (idx >= 0) {
      ret.emplace_back(s.substr(idx - T[idx] + 1, T[idx]));
      idx -= T[idx];
    }
    reverse(ret.begin(), ret.end());
  }
  return ret;
}
// @exclude

// Verify the strings in ans can be assembled into s.
void check_ans(const string& s, vector<string>& ans) {
  string temp;
  cout << s << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << ' ';
    temp += ans[i];
  }
  cout << endl;
  assert(!ans.size() || !s.compare(temp));
}

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    unordered_set<string> dictionary;
    string target;
    if (argc >= 3) {
      target = argv[1];
      for (int i = 3; i < argc; ++i) {
        dictionary.emplace(argv[i]);
      }
    } else if (argc == 2) {
      target = argv[1];
      uniform_int_distribution<int> dis(1, 10000);
      int n = dis(gen);
      while (n--) {
        uniform_int_distribution<int> dis(1, 15);
        dictionary.emplace(rand_string(dis(gen)));
      }
    } else {
      uniform_int_distribution<int> dis(1, 50);
      target = rand_string(dis(gen));
      uniform_int_distribution<int> n_dis(1, 10000);
      int n = n_dis(gen);
      while (n--) {
        uniform_int_distribution<int> dis(1, 15);
        dictionary.emplace(rand_string(dis(gen)));
      }
    }
    vector<string> ans(word_breaking(target, dictionary));
    check_ans(target, ans);
    if (argc == 3) {
      break;
    }
  }
  return 0;
}
