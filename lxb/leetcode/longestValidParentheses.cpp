http://oj.leetcode.com/problems/longest-valid-parentheses/
/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

Solution: 
1. DP.
   DP[i] means start from index i, till ends of len-1, the maximun num of valid parenthesis. 
   So if S[i] is ')', DP[i] = 0;
2. Idea is from http://blog.csdn.net/abcbc/article/details/8826782


class Solution {
public:
    int longestValidParentheses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.size();
        
        if (n < 2) return 0;
        
        vector<int> DP(n, 0);
        DP[n-1] = 0;
        
        int maxNum = 0;
        
        for (int i=n-2; i>=0; i--)
        {
            if (s[i] == '('){
                int j = i + 1 + DP[i+1];
                if (j < n && s[j] == ')'){
                    DP[i] = 2 + DP[i+1];
                    
                    if (j<n-1){
                        DP[i] += DP[j+1];
                    }    
                }
            }
            
            maxNum = max(maxNum, DP[i]);
        }
        
        return maxNum;
    }
};
