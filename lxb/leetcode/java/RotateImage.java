/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

//Focus: 1. cc150 method.
	 2. Identify the position for each of 4 point on top,right,bottom,left
	    first, last, offset and draw graph to help simplify this.

public class Solution {
    public void rotate(int[][] matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = matrix.length;
        
        for (int layer=0; layer<n/2; ++layer){
            int first = layer;
            int last = n - 1 - layer; 
            for (int j=first; j<last; ++j){
                int offset = j - first;
                int top = matrix[first][j];
                
                matrix[first][j] = matrix[last-offset][first];
                matrix[last-offset][first] = matrix[last][last-offset];
                matrix[last][last-offset] = matrix[j][last];
                matrix[j][last] = top;
            }
        }
    }
}
