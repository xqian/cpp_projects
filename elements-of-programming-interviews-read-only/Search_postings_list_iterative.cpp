// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <memory>
#include <stack>

using std::make_shared;
using std::shared_ptr;
using std::stack;

template <typename T>
struct node_t {
  T order;
  shared_ptr<node_t<T>> next, jump;
};

// @include
template <typename T>
void search_postings_list(const shared_ptr<node_t<T>>& L) {
  stack<shared_ptr<node_t<T>>> s;
  int order = 0;
  s.emplace(L);
  while (!s.empty()) {
    shared_ptr<node_t<T>> curr = s.top();
    s.pop();
    if (curr && curr->order == -1) {
      curr->order = order++;
      s.emplace(curr->next);
      s.emplace(curr->jump);
    }
  }
}
// @exclude

int main(int argc, char* argv[]) {
  shared_ptr<node_t<int>> L = nullptr, curr;
  curr = L;
  // Build a linked list L->1->2->3->4->5->nullptr.
  for (size_t i = 0; i < 5; ++i) {
    shared_ptr<node_t<int>> temp =
        make_shared<node_t<int>>(node_t<int>{-1, nullptr, nullptr});
    if (curr) {
      curr->next = temp;
      curr = temp;
    } else {
      curr = L = temp;
    }
  }
  L->jump = nullptr;                    // no jump from 1
  L->next->jump = L->next->next->next;  // 2's jump points to 4
  L->next->next->jump = L;              // 3's jump points to 1
  L->next->next->next->jump = nullptr;  // no jump from 4
  L->next->next->next->next->jump =
      L->next->next->next->next;  // 5's jump points to 5
  shared_ptr<node_t<int>> temp = L;
  search_postings_list(L);
  // output the jump-first order, it should be 0, 1, 4, 2, 3
  assert(temp->order == 0);
  temp = temp->next;
  assert(temp->order == 1);
  temp = temp->next;
  assert(temp->order == 4);
  temp = temp->next;
  assert(temp->order == 2);
  temp = temp->next;
  assert(temp->order == 3);
  return 0;
}
