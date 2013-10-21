http://oj.leetcode.com/submissions/detail/706539/

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
