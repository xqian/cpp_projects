/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
Focus:  1. for each step, we can get the farest position it can jump.
	2. How to choose next step: choose furthest one jump in range identified in step 1.
public class Solution {
    public int jump(int[] A) {
        if (A.length == 1) return 0;
        
        int last = A.length;
        int start = 0;
        int step = 0;
        
        while (start < last - 1) {
            step++;
            
            if (start + A[start] >= last - 1) {
                return step;
            }
            
            int mx = start;
            for (int i = start; i <= start + A[start]; ++i) {
                if (i + A[i] > mx + A[mx]) {
                    mx = i;
                }
            }
            
            start = mx;
        }
        
        return step;
    }
}
