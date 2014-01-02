/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

//Focus: 1. handle special case in the beginning.
	 2. array init. int[] dp=new int[n]; 
public class Solution {
    public int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        // handle special case
        if (n <= 2) return n;  
        
        int[] dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i=3; i<=n; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
        
    }
}
