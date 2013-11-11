// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <queue>
#include <random>
#include <string>
#include <sstream>
#include <vector>

using std::array;
using std::cout;
using std::default_random_engine;
using std::endl;
using std::istringstream;
using std::max;
using std::priority_queue;
using std::random_device;
using std::string;
using std::stringstream;
using std::swap;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::vector;

// @include
class Star {
 public:
  // The distance between this star to the Earth.
  double distance() const { return sqrt(x_ * x_ + y_ * y_ + z_ * z_); }

  bool operator<(const Star& s) const { return distance() < s.distance(); }

  int ID_;
  double x_, y_, z_;
};

vector<Star> find_closest_k_stars(istringstream& sin, int k) {
  // Use max_heap to find the closest k stars.
  priority_queue<Star, vector<Star>> max_heap;
  string line;

  // Record the first k stars.
  while (getline(sin, line)) {
    stringstream line_stream(line);
    string buf;
    getline(line_stream, buf, ',');
    int ID = stoi(buf);
    array<double, 3> data;  // stores x, y, and z.
    for (int i = 0; i < 3; ++i) {
      getline(line_stream, buf, ',');
      data[i] = stod(buf);
    }
    Star s{ID, data[0], data[1], data[2]};

    if (max_heap.size() == k) {
      // Compare the top of heap with the incoming star.
      Star far_star = max_heap.top();
      if (s < far_star) {
        max_heap.pop();
        max_heap.emplace(s);
      }
    } else {
      max_heap.emplace(s);
    }
  }

  // Store the closest k stars.
  vector<Star> closest_stars;
  while (!max_heap.empty()) {
    closest_stars.emplace_back(max_heap.top());
    max_heap.pop();
  }
  return closest_stars;
}
// @exclude

int partition(vector<Star>* stars, int left, int right, int pivot_index) {
  double pivot_value((*stars)[pivot_index].distance());
  swap((*stars)[pivot_index], (*stars)[right]);
  int less_index = left;
  for (int i = left; i < right; ++i) {
    if ((*stars)[i].distance() < pivot_value) {
      swap((*stars)[i], (*stars)[less_index++]);
    }
  }
  swap((*stars)[right], (*stars)[less_index]);
  return less_index;
}

vector<Star> select_k(vector<Star> stars, int k) {
  if (stars.size() <= k) {
    return stars;
  }

  default_random_engine gen((random_device())());
  int left = 0, right = stars.size() - 1, pivot_index;
  while (left <= right) {
    uniform_int_distribution<int> dis(left, right);
    pivot_index = partition(&stars, left, right, dis(gen));
    if (k - 1 < pivot_index) {
      right = pivot_index - 1;
    } else if (k - 1 > pivot_index) {
      left = pivot_index + 1;
    } else {  // k - 1 == pivot_index
      break;
    }
  }

  vector<Star> closest_stars;
  double dist(stars[pivot_index].distance());
  for (int i = 0; i < stars.size(); ++i) {
    if (dist >= stars[i].distance()) {
      closest_stars.emplace_back(stars[i]);
    }
  }
  return closest_stars;
}

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    int num, k;
    if (argc == 2) {
      num = atoi(argv[1]);
      uniform_int_distribution<int> dis(1, num);
      k = dis(gen);
    } else if (argc == 3) {
      num = atoi(argv[1]);
      k = atoi(argv[2]);
    } else {
      uniform_int_distribution<int> num_dis(1, 10000);
      num = num_dis(gen);
      uniform_int_distribution<int> k_dis(1, num);
      k = k_dis(gen);
    }
    vector<Star> stars;
    // randomly generate num of stars
    uniform_real_distribution<double> dis(0, 100000);
    for (int i = 0; i < num; ++i) {
      stars.emplace_back(Star{i, dis(gen), dis(gen), dis(gen)});
    }
    string s;
    for (int i = 0; i < num; ++i) {
      stringstream ss;
      ss << stars[i].ID_ << ',' << stars[i].x_ << ',' << stars[i].y_ << ','
         << stars[i].z_ << endl;
      s += ss.str();
      // cout << stars[i].ID_ << ' ' << stars[i].distance() << endl;
    }
    istringstream sin(s);
    vector<Star> closest_stars(find_closest_k_stars(sin, k));
    vector<Star> selected_stars(select_k(stars, k));
    sort(selected_stars.begin(), selected_stars.end());
    sort(stars.begin(), stars.end());
    cout << k << endl;
    // assert(stars[k - 1].ID_ == closest_stars[0].ID_);
    assert(stars[k - 1].distance() == selected_stars.back().distance());
  }
  return 0;
}
