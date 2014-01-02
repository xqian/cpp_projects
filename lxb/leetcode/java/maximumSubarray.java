/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/
public class Solution {
    public int maxSubArray(int[] A) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        assert A.length > 0;
        int[] dp = new int[A.length];
        /*
        Arrays.fill(dp, 123);  //example to init array to default value. It's 0 by default.
        */
        dp[0] = A[0];
        int maxRes = dp[0];
        
        for (int i=1; i<A.length; ++i){
            dp[i] = Math.max(dp[i-1] + A[i], A[i]);
            if (dp[i] > maxRes) maxRes = dp[i];
        }
        
        return maxRes;
    }
}
