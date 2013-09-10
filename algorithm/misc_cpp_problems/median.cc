#include "iostream"
#include "string"
#include "vector"
#include "assert.h"
#include "algorithm"
#include "map"
#include <iterator>
#include "unordered_map"
#include "cmath"
using namespace std;

/*
 * utility
 * */
#define debug_print(...) do {std::cerr<<__func__<<"("<<__LINE__<<"): "<<__VA_ARGS__;} while(0)
//#define debug_print(...)


class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        size_t ts= m+n;
        bool is_even= false;
        size_t middle=ts/2; //odd number is this one, even is middle, middle-1
        if (ts%2==0) is_even = true;
        int pre;
        int last;
        debug_print("is_e:"<<is_even<<", middle:"<<middle<<endl);
        for(size_t mi=0,ni=0;mi+ni<ts;)
        {
            if ( is_even && mi+ni==middle)
            {
                debug_print("mi:"<<mi<<", ni:"<<ni<<", p:"<<last<<endl);
                pre=last;
            }

            if ( mi<m && ( ni==n || A[mi]<B[ni]  ) ) 
            {
                last=A[mi];
                debug_print("mi:"<<mi<<", ni:"<<ni<<", l:"<<last<<endl);
                assert(mi<m);
                mi++;
            }
            else
            {
                last=B[ni];
                debug_print("mi:"<<mi<<", ni:"<<ni<<", l:"<<last<<endl);
                assert(ni<n);
                ni++;
            }

            debug_print("mi:"<<mi<<", a:"<<A[mi]<<", ni:"<<ni<<", b:"<<B[ni]<<endl);
            if (mi+ni==middle+1)
            {
                if (is_even)
                {
                    debug_print("mi:"<<mi<<", ni:"<<ni<<", r:"<<(pre+last)*0.5<<endl);
                    return (pre+last)*0.5;
                }
                else
                {
                    debug_print("mi:"<<mi<<", ni:"<<ni<<", last:"<<last<<endl);
                    return last;
                }
            }
        }
        return last;
    }
};

void test()
{
    Solution s;
    int arr1[]={5,25,75,80};
    int arr2[]={1,2,3,4,5};
    double m=s.findMedianSortedArrays(arr1, 3,arr2,2);
    assert(abs(m-5)<0.001);
    m=s.findMedianSortedArrays(arr1, 4,arr2,2);
    assert(abs(m-15)<0.001);
    m=s.findMedianSortedArrays(arr1, 3,arr2,5);
    assert(abs(m-4.5)<0.001);
    m=s.findMedianSortedArrays(arr1, 1,arr2,1);
    assert(abs(m-3)<0.001);
    m=s.findMedianSortedArrays(arr1, 1,arr2,2);
    assert(abs(m-2)<0.001);
}

int main()
{
    test();
    return 0;
}
