http://oj.leetcode.com/problems/search-in-rotated-sorted-array/
/*Question:
  Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

// Notes: Apply Binary search in the section which is restrictly increasing.

class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = low + (high-low+1) / 2;
            if (A[mid] == target) return mid;
            
            // reduce half space
            if (A[low] < A[mid]){
                //left part is strictly increasing
                if (A[low] <= target && target < A[mid]) high = mid - 1;
                else low = mid + 1;
            }else{
                //right part is strictly increasing
                if (A[high] >= target && target > A[mid]) low = mid + 1;
                else high = mid - 1;
            }
        }
            
        return -1;
    }
};
