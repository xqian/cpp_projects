/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
//Focus: 1. test cases to cover boundary.
public class Solution {
    public int searchInsert(int[] A, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int high = A.length - 1;
        int low = 0;
        
        while (low <= high){
            int mid = low + (high-low)/2;
            if (A[mid] == target) return mid;
            else if (A[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        
        return low;
    }
}
