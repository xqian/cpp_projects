/*
 * surrounded_regions.cc
 *
 *  Created on: Jun 13, 2013
 *      Author: xqian
 */


#include "union_set.h"

int debug_level=1;


class Solution {
public:
    static inline size_t get_index(const size_t& x, const size_t& y)
    {
      assert(x<(1<<16));
      return (x<<16)+y;
    }

    static void get_xy(const size_t& index, size_t& x, size_t& y)
        {
          size_t mask=0xffff;
          x=index>>16;
          y=(index&mask);
        }

    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      const size_t L1=board.size();
      const size_t L2=board.begin()->size();
      unordered_map<size_t,bool> visited;
      UnionSet<size_t> uset;
      int neigbour_displacement_arr[]={-1, 1, (int) ((-1)*L2), (int)L2};
      vector<int> neigbour_displacement(neigbour_displacement_arr, 
                           neigbour_displacement_arr
                          +sizeof(neigbour_displacement_arr)/sizeof(neigbour_displacement_arr[0]));
      const size_t init_parent=0xffffffff;

      for(size_t i1=0;i1<L1;i1++)
        for(size_t i2=0;i1<L2;i2++)
        {
          if ()
          {
            size_t parent=;
            //up
            if (i1>=1)
            {
              if board[i1-1][i2]
              parent=get_index(i1-1,i2);

            }
          }
        }
    }
};

void test2(size_t x, size_t y)
{
  Solution s1;
  size_t my_x=x;
  size_t my_y=y;
  cout<<s1.get_index(x,y)<<endl;
  s1.get_xy(s1.get_index(x,y),x,y);
  cout<<x<<", :"<<y<<endl;
  assert(x==my_x&&y==my_y);
}
void test1()
{
  UnionSet<int> uset;
  uset.union_together(10,10);
  uset.union_together(50,10);
  uset.union_together(40,50);

  uset.union_together(20,20);
  uset.union_together(70,20);

  assert(uset.is_same(70,40)==false);

  uset.union_together(20,10);
  assert(uset.is_same(70,40)!=false);
  cout<<(1<<16)<<","<<(size_t)(1<<31)<<endl;
  test2(1,2);
  test2(1000,20000);
}

int main()
{
  test1();
}

