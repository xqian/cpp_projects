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
