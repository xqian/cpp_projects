/*
 * trappingRainWater.cc
 *
 *  Created on: May 28, 2013
 *      Author: Xin
 *      http://leetcode.com/onlinejudge#question_42
 */
#include <iostream>
#include "assert.h"
using namespace std;

class Solution
{
public:
  bool haveMiddleHigherPoint(const int elevation[], size_t range_begin,
      size_t range_end, size_t& index, int& value)
  {
    int boundary_value = min(elevation[range_begin], elevation[range_end]);
    value = 0;
    bool result = false;
    for (size_t i = range_begin + 1; i < range_end; i++)
      {
      if (elevation[i] > boundary_value)
        {
        result = true;
        if (elevation[i] > value)
          {
          value = elevation[i];
          index = i;
          }
        }
      }
    return result;
  }

  int water_amount(int elevation[], size_t range_begin, size_t range_end)
  {
    size_t middle_high_index;
    int middle_high_value;
    if (haveMiddleHigherPoint(elevation, range_begin, range_end,
        middle_high_index, middle_high_value))
      {
      return water_amount(elevation, range_begin, middle_high_index)
          + water_amount(elevation, middle_high_index, range_end);
      }
    else
      {
      int high_value = min(elevation[range_begin], elevation[range_end]);
      int mount = 0;
      for (size_t i = range_begin; i <= range_end; i++)
        {
        if (elevation[i] < high_value)
          {
          mount += high_value - elevation[i];
          }
        }
      return mount;
      }
  }

  int trap(int A[], int n)
  {
    if (n>0)
      return water_amount(A, 0, n - 1);
    else
      return water_amount(A, 0, 0);
  }

};
/*
 *
 input  output  expected
 []     0
 [0]    0
 [1]    0
 [0,2,0]    0
 [2,0,2]    2
 [4,2,3]    1
 [2,1,0,2]      3
 [5,4,1,2]      1
 [4,2,0,3,2,5]      9
 [4,2,0,3,2,4,3,4]      10
 [5,5,1,7,1,1,5,2,7,6]      23
 [0,1,0,2,1,0,1,3,2,1,2,1]      6
 [6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3]      83

 * */

int main()
{
  Solution s1;
  struct test
  {
    int l;
    int expect;
    int a[256];
  };
  struct test cases[] =
    {
        {12 , 6, {0,1,0,2, 1,0,1,3, 2,1,2,1}}, //0
        {0,0,{1}},//1
        {1,0,{1}},//2
        {1,0,{1}},//3
        {27,83,{6,4,2,0, 3,2,0,3, 1,4,5,3, 2,7,5,3, 0,1,2,1, 3,4,6,8, 1,3}}//4
    };
  for(int i=0;i<5;i++)
    assert(s1.trap(cases[i].a, cases[i].l)==cases[i].expect);

}

