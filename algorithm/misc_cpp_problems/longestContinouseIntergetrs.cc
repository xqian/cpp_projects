/*
 * longestContinouseIntergetrs.cc
 *
 *  Created on: Jun 7, 2013
 *      Author: xqian
 */
#include <iostream>
#include <string.h>
#include <assert.h>
#include <string>
#include <vector>
#include <list>
#include <time.h>
#include <limits.h>
#include <iterator>
#include <tr1/unordered_set>
#include <deque>
#include <tr1/unordered_map>
using namespace std;

//#define debug_print(...) do {std::cout<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)
//#define debug_do(...) do { __VA_ARGS__;} while(0)
#define debug_print(...)
#define debug_do(...)
//using namespace std::tr1;


class LongestSum
{
public:
  int sum;
  size_t b;
  size_t e;
  LongestSum()
  {
    sum=INT_MIN;
    b=0;
    e=0;
  };
  LongestSum(int in_sum, size_t in_b, size_t in_e)
  {
    sum=in_sum;
    b=in_b;
    e=in_e;
  }
};

ostream& operator <<(ostream& o, const LongestSum& l)
{
  o<<"sum:"<<l.sum<<", b:"<<l.b<<", e:"<<l.e;
  return o;
}

/*
 * using end to track the longest positive sum to the end
 * using best to track the largest sum so far
 * */

LongestSum findLongestSum(vector<int> v)
{
  LongestSum best=LongestSum(INT_MIN,0,0);
  LongestSum end=LongestSum(0,0,0);

  for(size_t i=0; i<v.size();i++)
    {
      if ((end.sum+v[i])>=0) //using 0 will keep the sequence
        {
        end.sum+=v[i];
        (end.e)++;
        }
      else
        {
        end.sum=0;
        end.b=i+1;
        end.e=i+1;
        }
      if (end.sum>best.sum)
        {
        if (end.sum==0)
          {
          if (best.sum<v[i])
            {
            best.sum=v[i];
            best.b=i;
            best.e=i+1;
            }
          }
        else
          {
          best=end;
          }
        }
      debug_print("i:"<<i<<endl<<"    e:"<<end<<endl<<"    b:"<<best<<endl);
    }

  return best;
}

int main()
{
  int a[]={-1, 2, 3, 4, 5, -9, 10};
  //  e     0, 2  5  9  14  5  15
  //  b     0, 2, 5, 9, 14, 14,15
  //  i     0, 1, 2, 3,  4, 5 , 6
  int b[]={-2, -1, -3, 4, 5, -9, 10};
  //  e     0   0   0  4  5   0  10
  //  b     -2  -1  -1 4  9   9  10
  //  i      0,  1,  2,3, 4,  5, 6
  LongestSum result;
  result= findLongestSum(vector<int>(a,a+sizeof(a)/sizeof(a[0])-1));
  assert(result.sum == 14);
  assert(result.b == 1);
  assert(result.e == 5);

  result = findLongestSum(vector<int>(a,a+sizeof(a)/sizeof(a[0])));
  assert(result.sum == 15);
  assert(result.b == 1);
  assert(result.e == 7);


  result = findLongestSum(vector<int>(a,a+1));
  assert(result.sum == -1);
  assert(result.b == 0);
  assert(result.e == 1);

  result = findLongestSum(vector<int>(b,b+sizeof(b)/sizeof(b[0])));
  assert(result.sum == 10);
  assert(result.b == 6 || result.b == 3);
  assert(result.e == 7);

  result = findLongestSum(vector<int>(b,b+3));
  assert(result.sum == -1);
  assert(result.b == 1);
  assert(result.e == 2);
}
