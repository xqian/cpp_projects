// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#ifndef SOLUTIONS_CAN_STRING_BE_PALINDROME_SORTING_H_
#define SOLUTIONS_CAN_STRING_BE_PALINDROME_SORTING_H_

#include <algorithm>
#include <string>

using std::string;

// @include
bool can_string_be_a_palindrome_sorting(string* s) {
  sort(s->begin(), s->end());
  int odd_count = 0, num_curr_char = 1;

  for (int i = 1; i < s->size() && odd_count <= 1; ++i) {
    if ((*s)[i] != (*s)[i - 1]) {
      if (num_curr_char & 1) {
        ++odd_count;
      }
      num_curr_char = 1;
    } else {
      ++num_curr_char;
    }
  }
  if (num_curr_char & 1) {
    ++odd_count;
  }

  // A string can be permuted as a palindrome if the number of odd time
  // chars <= 1.
  return odd_count <= 1;
}
// @exclude
#endif  // SOLUTIONS_CAN_STRING_BE_PALINDROME_SORTING_H_
