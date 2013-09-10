#include "iostream"
#include "string"
#include "vector"
#include "assert.h"
#include "algorithm"
#include "map"
#include <iterator>
#include "unordered_map"
using namespace std;

/*
 * utility
 * */
//#define debug_print(...) do {std::cerr<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)
#define debug_print(...)

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
       std::unordered_map<int, size_t> v_p;
       std::vector<int> result;
       for(size_t i=0; i< numbers.size(); i++)
            v_p[numbers[i]]=i;
        
       for(size_t i=0; i< numbers.size(); i++)
       {
       		debug_print("i:"<<i<<",n:"<<numbers[i]<<endl);
           if (numbers[i]<target)
           {
               auto it=v_p.find(target-numbers[i]);
               if (it!=v_p.end())
               {
               	  result.push_back(i);
               	  result.push_back(it->second);
               	  debug_print("f, i1:"<<i<<", i2:"<<it->second<<endl);
               	  return result;
               }
           }
           
       } 
       return result;    
    }
};

void test()
{
	Solution s;
    int arr[]={1,2,4,5};
    vector<int> test_v(arr,arr+4);
    std::ostream_iterator<int> out_it (std::cout,", ");
    vector<int> result(s.twoSum(test_v,6));
    assert(result[0]==0);
    assert(result[1]==3);


}

void test2()
{
	Solution s;
    int arr1[]={5,75,25};
    vector<int> test_v1(arr1,sizeof(arr1)/sizeof(arr1[0])+arr1);
    vector<int> result1(s.twoSum(test_v1,100));
    assert(result1[0]==1);
    assert(result1[1]==2);
}

int main()
{
	test();
	test2();
    return 0;
}
