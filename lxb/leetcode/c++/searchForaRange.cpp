http://oj.leetcode.com/problems/search-for-a-range/

/*
  Question:
  Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Discuss


*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int lower_bound,upper_bound;
        vector<int> result;
        
        int L = 0;
        int R = n-1;
        
        //find lower_bound
        while(L<R){
            int mid = L + (R-L)/2;
            if (A[mid] >= target){
                R = mid;
            }else{
                L = mid+1;
            }
        }
        
        
        lower_bound = (A[R] == target) ? R : -1;
        if (lower_bound == -1){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        
        // find upper_bound
        L=0;
        R=n-1;
        
        while (L<R){
            int mid = L + (R-L+1)/2;
            if (A[mid] > target)    R = mid - 1;
            else L=mid;
        }
        upper_bound = L;
    
        result.push_back(lower_bound);
        result.push_back(upper_bound);
        
        return result;
    }
};
