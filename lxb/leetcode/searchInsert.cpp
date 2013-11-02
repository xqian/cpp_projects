http://oj.leetcode.com/problems/search-insert-position/

/*
  Question:
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int L = 0;
        int R = n-1;
        
        while (L<=R){
            int mid = L + (R-L+1)/2;
            if (A[mid] == target) return mid;
            else if (A[mid] > target){
                R = mid - 1;
            }else{
                L = mid + 1;
            }
        }
        
        // not find
        return L;
    }
};
