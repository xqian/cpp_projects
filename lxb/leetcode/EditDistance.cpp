http://oj.leetcode.com/submissions/detail/706539/

/*
 Question:
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n1 = word1.size();
        int n2 = word2.size();
        
        // State S[n1+1][n2+1]
        vector<vector<int> > S(n1+1, vector<int>(n2+1));
        
        //init
        for (int i = 0; i<= n1;i++) S[i][0] = i;
        for (int j = 0; j<= n2;j++) S[0][j] = j;
        
        // DP. bottom up (O(m*n))
        for (int i = 0; i<n1; i++)
        for (int j = 0; j<n2; j++)
        {  
            //S[i,j] = S[i-1,j-1] if ==)
            if (word1[i] == word2[j]) S[i+1][j+1] = S[i][j];
            else{
                S[i+1][j+1] = min(min(S[i][j+1],S[i+1][j]),S[i][j]) + 1;
            }
        }
        
        return S[n1][n2];
    }
};

Method 2 : space (O(n))
	1. Trick: how to record the four value. upperLeft, upper, left.

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = word1.size();
        int n = word2.size();
        
        vector<int> DP(n+1);
        
        //init
        for (int i=0; i<=n; ++i){
            DP[i] = i;
        }
        
        //DP
        for (int i=1; i<=m; i++)
        {
            int upperLeftBackup = DP[0];
            DP[0] = i;
        
            for (int j=1; j<=n; j++)
            {
                int upperLeft = upperLeftBackup;
                upperLeftBackup = DP[j];
                
                if (word1[i-1] == word2[j-1]){
                    DP[j] = upperLeft;
                }else{
                    DP[j] = min( min(DP[j-1], DP[j]), upperLeft) + 1;  // DP[j-1]: left, DP[j] : upper, upperLeft: dp[i-1][j-1]
                }
            }
        }
        
        return DP[n];
    }
};
