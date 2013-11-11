// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::ios;
using std::istringstream;
using std::pair;
using std::random_device;
using std::string;
using std::uniform_int_distribution;
using std::unordered_map;
using std::vector;

string rand_string(int len) {
  string ret;
  default_random_engine gen((random_device())());
  while (len--) {
    uniform_int_distribution<int> dis('a', 'z');
    ret += dis(gen);
  }
  return ret;
}

// @include
vector<string> Search_frequent_items(istringstream* sin, int k) {
  // Find the candidates which may occur >= n / k times.
  string buf;
  unordered_map<string, int> hash;
  int n = 0;  // count the number of strings.

  while (*sin >> buf) {
    ++hash[buf], ++n;
    // Detecting k + 1 items in hash, at least one of them must have exactly 1
    // in it. We will discard those k + 1 items by 1 for each.
    if (hash.size() == k + 1) {
      auto it = hash.begin();
      while (it != hash.end()) {
        if (--(it->second) == 0) {
          hash.erase(it++);  // remove the empty entry.
        } else {
          ++it;
        }
      }
    }
  }

  // Reset hash for the following counting.
  for (auto& it : hash) {
    it.second = 0;
  }

  // Reset the stream and read it again.
  sin->clear();
  sin->seekg(0, ios::beg);
  // Count the occurrence of each candidate word.
  while (*sin >> buf) {
    auto it = hash.find(buf);
    if (it != hash.end()) {
      ++it->second;
    }
  }

  vector<string> ret;
  for (const pair<string, int>& it : hash) {
    // Select the word which occurs >= n / k times.
    if (it.second >= static_cast<double>(n) / k) {
      ret.emplace_back(it.first);
    }
  }
  return ret;
}
// @exclude

void check_ans(vector<string>* stream, int k, vector<string>* items) {
  sort(items->begin(), items->end());
  sort(stream->begin(), stream->end());
  int count = 1, idx = 0;
  for (int i = 1; i < stream->size(); ++i) {
    if ((*stream)[i].compare((*stream)[i - 1])) {
      if (count >= static_cast<double>(stream->size()) / k) {
        assert(idx < items->size());
        assert((*stream)[i - 1].compare((*items)[idx++]) == 0);
      }
      count = 1;
    } else {
      ++count;
    }
  }
  if (count >= static_cast<double>(stream->size()) / k) {
    assert((*stream).back().compare((*items)[idx++]) == 0);
  }
  assert(idx == items->size());
}

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    cout << times << endl;
    vector<string> stream;
    int n, k;
    if (argc == 2) {
      n = atoi(argv[1]);
      uniform_int_distribution<int> k_dis(1, n);
      k = k_dis(gen);
    } else if (argc == 3) {
      n = atoi(argv[1]);
      k = atoi(argv[2]);
    } else {
      uniform_int_distribution<int> n_dis(0, 99999);
      n = n_dis(gen);
      uniform_int_distribution<int> k_dis(1, n);
      k = k_dis(gen);
    }
    for (int i = 0; i < n; ++i) {
      uniform_int_distribution<int> dis(1, 5);
      stream.emplace_back(rand_string(dis(gen)));
    }
    string s;
    for (int i = 0; i < stream.size(); ++i) {
      s += stream[i];
      s += ' ';
    }
    istringstream sin(s);
    vector<string> items = Search_frequent_items(&sin, k);
    check_ans(&stream, k, &items);
  }
  return 0;
}
