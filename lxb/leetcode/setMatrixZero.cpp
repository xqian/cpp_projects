http://oj.leetcode.com/problems/set-matrix-zeroes/

/* Question:
  Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> row(matrix.size(),1);
        vector<int> col(matrix[0].size(),1);
        
        int r = matrix.size();
        int c = matrix[0].size();
        for (int i=r-1; i>=0; i--)
            for (int j=c-1; j>=0; j--)
            if (matrix[i][j] == 0){
                row[i] = 0;
                col[j] = 0;
            }
        
        for (int i=r-1; i>=0; i--)
            for (int j=c-1; j>=0; j--)
            if (row[i]== 0 || col[j] == 0){
                matrix[i][j] = 0;
        }
    }
};
