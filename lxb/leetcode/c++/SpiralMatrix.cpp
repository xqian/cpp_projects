http://oj.leetcode.com/problems/spiral-matrix/
/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

Solution: 1. It can be or not squre! It can be a rectangle.
	  2. So we need two boundary check (minRow,maxRow) and (minCol,maxCol);
	  3. Modify the value each time we move . top, right, bottom, left and do the boundary check.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<int> result;
        int rowMin = 0;
        int rowMax = matrix.size() - 1;
        
        if (rowMax < 0) return result; 
        
        int colMin = 0;
        int colMax = matrix[0].size() -1;
        
        while (true)
        {
            //top
            for (int col=colMin; col <= colMax; col++) result.push_back(matrix[rowMin][col]);
            if (++rowMin > rowMax) break;
            
            //right
            for (int row=rowMin; row <=rowMax; row++) result.push_back(matrix[row][colMax]);
            if (colMin > --colMax) break;
            
            //bottom
            for (int col=colMax; col>=colMin; col--) result.push_back(matrix[rowMax][col]);
            if (rowMin > --rowMax) break;
            
            //left
            for (int row=rowMax; row>=rowMin; row--) result.push_back(matrix[row][colMin]);
            if (++colMin > colMax) break;

        }
        
        return result;
    }
};
