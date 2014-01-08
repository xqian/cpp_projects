//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
// Focus: use seperate row/col to record 0. Two round of travel.

public class Solution {
    public void setZeroes(int[][] matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (matrix.length == 0) return;
        
        int[] row = new int[matrix.length];
        int[] col = new int[matrix[0].length];
        
        for (int i=0; i<matrix.length; ++i)
        for (int j=0; j<matrix[0].length; ++j){
            if (matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
        
        for (int i=0; i<matrix.length; ++i)
        for (int j=0; j<matrix[0].length; ++j){
            if (row[i] == 1 || col[j] == 1){
                matrix[i][j] = 0;
            }
        }
        
    }
}
