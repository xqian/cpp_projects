/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

Discuss

*/

public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int rows = matrix.length;
        if (rows==0) return false;
        
        int cols = matrix[0].length;
        
        int r=0;
        int c=cols-1; 
        while (r<rows && c>=0){
            if (matrix[r][c] > target) {
                c--;
            }else if (matrix[r][c] < target){
                r++;
            }else{
                return true;
            }
        }
        
        return false;
    }

}
