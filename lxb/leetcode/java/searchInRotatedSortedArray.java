/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Discuss
*/
//Focus: 1. boundary value check. L<=H , int mid = L + (H-L+1)/2
	 2. apply binary search in the well sorted side.

public class Solution {
    public int search(int[] A, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int L = 0;
        int H = A.length - 1;
        
        while(L<=H){
            int mid = L + (H-L+1)/2;
            if (A[mid] == target) return mid;
            if (A[L] < A[mid]){
                //left side is well sorted.
                if (A[L] <= target && target < A[mid]){
                    H = mid - 1;
                }else{
                    L = mid + 1;
                }
            }else{
                //right side is well sorted.
                if (A[mid] < target && target <= A[H]){
                    L = mid + 1;
                }else{
                    H = mid - 1;
                }
            }
        }
        
        return -1;
    }
}
