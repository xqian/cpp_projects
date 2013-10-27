http://oj.leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int row = 0;
        int col = matrix[0].size() - 1;
        
        while (row < matrix.size() && col >= 0)
        {
            if (matrix[row][col] == target) return true;
            
            if (matrix[row][col] > target) col--;
            else row++;
        }
        
        return false;
    }
};
