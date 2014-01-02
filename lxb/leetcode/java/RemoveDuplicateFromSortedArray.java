/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/
public class Solution {
    public int removeDuplicates(int[] A) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (A.length == 0) return 0;
        
        int i=0;
        int j=1;
        
        while(j<A.length){
            if (A[j]==A[i]) j++;
            else A[++i] = A[j++];
        }
        
        return i+1;
    }
}
