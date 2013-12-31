http://oj.leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        //S[i][j] means the uniquePaths to reach grid [i,j]
        vector<vector<int> > S(m,vector<int>(n,0));
        
        //base
        for (int i=0; i< m; i++) S[i][0] = 1;
        for (int j = 0; j<n; j++) S[0][j] = 1;
        
        //Bottom up
        
        for (int i = 1; i<m; i++)
        for (int j = 1; j<n; j++)
        {
            S[i][j] = S[i-1][j] + S[i][j-1];
        }
        
        return S[m-1][n-1];
    }
};
