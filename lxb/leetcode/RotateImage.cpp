http://oj.leetcode.com/problems/rotate-image/

Notes: flip twice along diag-line and vertical. Pay special attention to boundary value. Use two dimenstion example to help figure out boundary.

/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/


class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = matrix.size();
        if (n<2) return;
        
        // rotate along clockwise diag line A[i,j] -> A[j,i]
        for (int row=0; row< n - 1; row++){
            for (int col=row+1; col < n ;col++ ){
                int tmp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = tmp;
            }
        }
        
        //then rotate along middle vertical line
        for (int row =0 ;row<n; row++)
        for (int col =0; col<n/2; col++ ){
            int tmp = matrix[row][col];
            matrix[row][col] = matrix[row][n-col-1];
            matrix[row][n-col-1] = tmp;
        }
        
        return;
    }
};
