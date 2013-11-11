// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <array>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

using std::array;
using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

// @include
struct Coordinate {
  bool operator==(const Coordinate& that) const {
    return x == that.x && y == that.y;
  }

  int x, y;
};

// Check cur is within maze and is a white pixel.
bool is_feasible(const Coordinate& cur, const vector<vector<int>>& maze) {
  return cur.x >= 0 && cur.x < maze.size() && cur.y >= 0 &&
         cur.y < maze[cur.x].size() && maze[cur.x][cur.y] == 0;
}

// Perform DFS to find a feasible path.
bool search_maze_helper(vector<vector<int>>* maze,
                        const Coordinate& cur,
                        const Coordinate& e,
                        vector<Coordinate>& path) {
  if (cur == e) {
    return true;
  }

  const array<array<int, 2>, 4> shift = {
      {{{0, 1}}, {{0, -1}}, {{1, 0}}, {{-1, 0}}}};

  for (const auto& s : shift) {
    Coordinate next{cur.x + s[0], cur.y + s[1]};
    if (is_feasible(next, *maze)) {
      (*maze)[next.x][next.y] = 1;
      path.emplace_back(next);
      if (search_maze_helper(maze, next, e, path)) {
        return true;
      }
      path.pop_back();
    }
  }
  return false;
}

vector<Coordinate> search_maze(vector<vector<int>> maze,
                               const Coordinate& s,
                               const Coordinate& e) {
  vector<Coordinate> path;
  maze[s.x][s.y] = 1;
  path.emplace_back(s);
  if (!search_maze_helper(&maze, s, e, path)) {
    path.pop_back();
  }
  return path;  // empty path means no path between s and e.
}
// @exclude

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1000; ++times) {
    int n, m;
    if (argc == 3) {
      n = atoi(argv[1]);
      m = atoi(argv[2]);
    } else {
      uniform_int_distribution<int> dis(1, 30);
      n = dis(gen);
      m = dis(gen);
    }
    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        uniform_int_distribution<int> zero_or_one(0, 1);
        maze[i][j] = zero_or_one(gen);
      }
    }
    vector<Coordinate> white;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (maze[i][j] == 0) {
          white.emplace_back(Coordinate{i, j});
        }
        cout << maze[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;
    if (white.size()) {
      uniform_int_distribution<int> dis(0, white.size() - 1);
      int start = dis(gen);
      int end = dis(gen);
      cout << white[start].x << ' ' << white[start].y << endl;
      cout << white[end].x << ' ' << white[end].y << endl;
      vector<Coordinate> path = search_maze(maze, white[start], white[end]);
      if (!path.empty()) {
        assert(white[start] == path.front() && white[end] == path.back());
      }
      for (int i = 0; i < path.size(); ++i) {
        if (i > 0) {
          assert(abs(path[i - 1].x - path[i].x) +
                     abs(path[i - 1].y - path[i].y) ==
                 1);
        }
        cout << '(' << path[i].x << ',' << path[i].y << ')' << endl;
      }
    }
  }
  return 0;
}
