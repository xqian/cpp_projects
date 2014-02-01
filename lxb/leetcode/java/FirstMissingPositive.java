/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
Focus:  1. Coding style :https://code.google.com/p/gtge/wiki/JavaCodeStyleGuideline
public class Solution {
    public int firstMissingPositive(int[] A) {
        int len = A.length;
        
        //find position 
        for (int i = 0; i < len; i++){
            if (A[i] - 1 != i && A[i] > 0 && A[i] - 1 < len
                    && A[i] != A[A[i]-1]) {
                int t = A[A[i] - 1];
                A[A[i] - 1] = A[i];
                A[i] = t;
                i--;
            }
        }
        
        // first misplaced value is the answer
        for (int j = 0; j < len; j++) {
            if (A[j] != j + 1) {
                return j + 1;
            }
        }
        
        // all good.
        return len + 1;
    }
}
