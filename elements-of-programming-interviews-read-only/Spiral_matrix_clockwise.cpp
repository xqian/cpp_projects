// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

// @include
void print_matrix_clockwise(const vector<vector<int>> &A, int offset) {
  if (offset == A.size() - offset - 1) {  // for matrix with odd size.
    cout << A[offset][offset];
  }

  for (int j = offset; j < A.size() - offset - 1; ++j) {
    cout << A[offset][j] << ' ';
  }
  for (int i = offset; i < A.size() - offset - 1; ++i) {
    cout << A[i][A.size() - offset - 1] << ' ';
  }
  for (int j = A.size() - offset - 1; j > offset; --j) {
    cout << A[A.size() - offset - 1][j] << ' ';
  }
  for (int i = A.size() - offset - 1; i > offset; --i) {
    cout << A[i][offset] << ' ';
  }
}

void print_matrix_in_spiral_order(const vector<vector<int>> &A) {
  for (int offset = 0; offset < ceil(0.5 * A.size()); ++offset) {
    print_matrix_clockwise(A, offset);
  }
}
// @exclude

int main(int argc, char *argv[]) {
  default_random_engine gen((random_device())());
  int N;
  if (argc == 2) {
    N = atoi(argv[1]);
  } else {
    uniform_int_distribution<int> dis(1, 50);
    N = dis(gen);
  }
  vector<vector<int>> A(N, vector<int>(N));
  int x = 1;
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < N; ++j) {
      A[i][j] = x++;
    }
  }
  print_matrix_in_spiral_order(A);
  return 0;
}
