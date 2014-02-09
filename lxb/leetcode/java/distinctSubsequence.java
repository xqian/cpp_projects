/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
Focus:  1. define dp[i][j] means T[0..i-1] and S[0..j-1] , the distinct subsequences number.
	2. init: dp[0][0] = 1, dp[i][0] = 0 dp[0][j] = 1
	3. for dp[i][j], it first dp[i][j] = dp[i][j-1] . if t[i] = s[j], dp[i][j] += dp[i-1][j-1]
public class Solution {
    public int numDistinct(String S, String T) {
        int[][] dp = new int[T.length() + 1][S.length() + 1];
        dp[0][0] = 1; // if both empty
        
        for (int i = 1; i <= T.length() ; ++i) {
            dp[i][0] = 0; // S is empty
        }
        
        for (int j = 1; j <= S.length() ; ++j) {
            dp[0][j] = 1; // T is empty
        }
        
        for (int i = 1; i <= T.length() ; ++i) {
            for (int j = 1; j <= S.length() ; ++j) {
                dp[i][j] = dp[i][j - 1];
                if (T.charAt(i - 1) == S.charAt(j - 1)) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[T.length()][S.length()];
    }
}
