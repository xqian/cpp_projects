http://oj.leetcode.com/submissions/detail/707064/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int> > S(row+1,vector<int>(col+1));
        
        //init
        S[0][0] = grid[0][0];
        for (int i=1; i < row; i++) S[i][0] = S[i-1][0] + grid[i][0];
        for (int j=1; j < col; j++) S[0][j] = S[0][j-1] + grid[0][j];
        
        //DP O(row * col)
        for (int i = 1; i < row; i++)
        for (int j = 1; j < col; j++)
        {
            //from upper or left
            S[i][j] = min(S[i-1][j],S[i][j-1]) + grid[i][j];
        }
        
        return S[row-1][col-1];
    }
};

//Method 2: define C type array with const.
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        const int m = grid.size();
        const int n = grid[0].size();
        
        int DP[m][n];
        
        DP[0][0] = grid[0][0];
        for (int row=1; row < m; row++)  DP[row][0] = DP[row-1][0] + grid[row][0];
        for (int col=1; col<n; col++) DP[0][col] = DP[0][col-1] +grid[0][col];
        
        for (int i=1; i<m; i++)
        for (int j=1; j<n; j++)
        {
            DP[i][j] = min(DP[i-1][j], DP[i][j-1]) + grid[i][j];
        }
        
        return DP[m-1][n-1];
    }
};
