// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <deque>
#include <iostream>
#include <limits>
#include <queue>
#include <random>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::deque;
using std::endl;
using std::numeric_limits;
using std::pair;
using std::random_device;
using std::set;
using std::uniform_int_distribution;
using std::vector;

// @include
struct GraphVertex {
  // distance stores (dis, #edges) pair.
  pair<int, int> distance = {numeric_limits<int>::max(), 0};
  vector<pair<GraphVertex*, int>> edges;
  int id;                       // the id of this vertex.
  GraphVertex* pred = nullptr;  // the predecessor in the shortest path.
};

struct Comp {
  bool operator()(const GraphVertex* lhs, const GraphVertex* rhs) const {
    return lhs->distance.first < rhs->distance.first ||
           (lhs->distance.first == rhs->distance.first &&
            lhs->distance.second < rhs->distance.second);
  }
};

void output_shortest_path(GraphVertex*& v) {
  if (v) {
    output_shortest_path(v->pred);
    cout << v->id << " ";
  }
}

void Dijkstra_shortest_path(GraphVertex* s, GraphVertex* t) {
  // Initialization the distance of starting point.
  s->distance = {0, 0};
  set<GraphVertex*, Comp> node_set;
  node_set.emplace(s);

  while (!node_set.empty()) {
    // Extract the minimum distance vertex from heap.
    GraphVertex* u = *node_set.cbegin();
    if (u == t) {
      break;
    }
    node_set.erase(node_set.cbegin());

    // Relax neighboring vertices of u.
    for (const auto& v : u->edges) {
      int v_distance = u->distance.first + v.second;
      int v_num_edges = u->distance.second + 1;
      if (v.first->distance.first > v_distance ||
          (v.first->distance.first == v_distance &&
           v.first->distance.second > v_num_edges)) {
        node_set.erase(v.first);
        v.first->pred = u;
        v.first->distance = {v_distance, v_num_edges};
        node_set.emplace(v.first);
      }
    }
  }

  // Output the shortest path with fewest edges.
  output_shortest_path(t);
}
// @exclude

// DBH test
void test() {
  vector<GraphVertex> G;
  for (int i = 0; i < 9; ++i) {
    G.emplace_back(GraphVertex());
    G[i].id = i;
  }

  // G[0] is the source node that connects to 8 other nodes.
  G[0].edges.push_back(pair<GraphVertex*, int>(&G[1], 13));  // 0-1
  G[1].edges.push_back(pair<GraphVertex*, int>(&G[0], 13));  // 1-0

  G[0].edges.push_back(pair<GraphVertex*, int>(&G[2], 24));  // 0-2
  G[2].edges.push_back(pair<GraphVertex*, int>(&G[0], 24));  // 2-0

  G[0].edges.push_back(pair<GraphVertex*, int>(&G[3], 28));  // 0-3
  G[3].edges.push_back(pair<GraphVertex*, int>(&G[0], 28));  // 3-0

  G[0].edges.push_back(pair<GraphVertex*, int>(&G[4], 25));  // 0-4
  G[4].edges.push_back(pair<GraphVertex*, int>(&G[0], 25));  // 4-0

  G[0].edges.push_back(pair<GraphVertex*, int>(&G[5], 30));  // 0-5
  G[5].edges.push_back(pair<GraphVertex*, int>(&G[0], 30));  // 5-0

  G[0].edges.push_back(pair<GraphVertex*, int>(&G[6], 31));  // 0-6
  G[6].edges.push_back(pair<GraphVertex*, int>(&G[0], 31));  // 6-0

  G[0].edges.push_back(pair<GraphVertex*, int>(&G[7], 10));  // 0-7
  G[7].edges.push_back(pair<GraphVertex*, int>(&G[0], 10));  // 7-0

  G[0].edges.push_back(pair<GraphVertex*, int>(&G[8], 29));  // 0-8
  G[8].edges.push_back(pair<GraphVertex*, int>(&G[0], 29));  // 8-0

  G[1].edges.push_back(pair<GraphVertex*, int>(&G[8], 7));  // 1-8
  G[8].edges.push_back(pair<GraphVertex*, int>(&G[1], 7));  // 8-1

  G[2].edges.push_back(pair<GraphVertex*, int>(&G[8], 1));  // 2-8
  G[8].edges.push_back(pair<GraphVertex*, int>(&G[2], 1));  // 8-2

  G[7].edges.push_back(pair<GraphVertex*, int>(&G[8], 16));  // 7-8
  G[8].edges.push_back(pair<GraphVertex*, int>(&G[7], 16));  // 8-7

  int s = 0;  // Source is G[0].
  int t = 2;  // Destination is G[2].

  // Minimum distance path should be:
  // G[0] => G[1] => G[8] => G[2],
  // distance is: 13 + 7 + 1 = 21.

  Dijkstra_shortest_path(&G[s], &G[t]);
  cout << endl << "Min distance: " << G[t].distance.first << endl;
  assert(G[t].distance.first == 21);
  cout << "Number of edges: " << G[t].distance.second << endl;
  assert(G[t].distance.second == 3);
}

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  int n;
  if (argc == 2) {
    n = atoi(argv[1]);
  } else {
    uniform_int_distribution<int> dis(2, 1000);
    n = dis(gen);
  }
  vector<GraphVertex> G;
  for (int i = 0; i < n; ++i) {
    G.emplace_back(GraphVertex());
  }
  uniform_int_distribution<int> dis(1, n * (n - 1) >> 1);
  int m = dis(gen);
  vector<deque<bool>> is_edge_exist(n, deque<bool>(n, false));
  // Make the graph as connected.
  for (int i = 1; i < n; ++i) {
    uniform_int_distribution<int> dis(1, 100);
    int len = dis(gen);
    G[i - 1].edges.emplace_back(&G[i], len);
    G[i].edges.emplace_back(&G[i - 1], len);
    is_edge_exist[i - 1][i] = is_edge_exist[i][i - 1] = true;
  }

  // Generate edges randomly.
  m -= (n - 1);
  uniform_int_distribution<int> dis_n(0, n - 1);
  while (m-- > 0) {
    int a, b;
    do {
      a = dis_n(gen), b = dis_n(gen);
    } while (a == b || is_edge_exist[a][b] == true);
    is_edge_exist[a][b] = is_edge_exist[b][a] = true;
    uniform_int_distribution<int> one_to_100(1, 100);
    int len = one_to_100(gen);
    G[a].edges.emplace_back(&G[b], len);
    G[b].edges.emplace_back(&G[a], len);
  }
  int s = dis_n(gen), t = dis_n(gen);
  for (int i = 0; i < G.size(); ++i) {
    G[i].id = i;
    for (const pair<GraphVertex*, int> e : G[i].edges) {
      cout << (e.first - &G[0]) << ' ' << e.second << ',';
    }
    cout << endl;
  }
  cout << "source = " << s << ", terminal = " << t << endl;
  Dijkstra_shortest_path(&G[s], &G[t]);
  cout << endl << G[t].distance.first << " " << G[t].distance.second << endl;
  test();
  return 0;
}
