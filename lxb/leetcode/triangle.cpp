http://oj.leetcode.com/problems/triangle/

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = triangle.size();
        if (n == 0) return 0;
        if (n == 1) return triangle[0][0];
        
        // define S[i,j] : from bottom to triangle, the minimum path sum including element triangle[i][j]
        // S[i,j] = min(S[i+1,j], S[i+1,j+1]) + triangle[i][j] 
        // init: last row S[i,j] = triangle[i][j]
        // In fact, triangle can be reused to save as DP Table
       
        for (int row=triangle.size()-2; row >= 0; row--)
        for (int col=0; col < row + 1; col++)
        { 
            triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);
        }
        
        return triangle[0][0];
    }
};


/* Method 2 */
http://oj.leetcode.com/problems/triangle/
Notes: It complains runtime error with cycle array.

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (triangle.empty()) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        
        // DP[i][j] : start from row i, col j, the minipath.
        // Cycle Array since only two rows are involoved.
        vector<vector<int> > DP(2, vector<int>(triangle[0].size(), INT_MAX));
        
        //Start from last line.
        for (int i=0; i< triangle[0].size(); i++)
        {
            DP[(triangle.size()-1)%2][i] = triangle[triangle.size()-1][i];
        }
        
        //DP
        for (int i=triangle.size()-2; i>=0; i--)
        for (int j=0; j<=i;j++)
        {
            DP[i%2][j] = min(DP[(i+1)%2][j], DP[(i+1)%2][j+1]) + triangle[i][j];
        }
        
        return DP[0][0];
    }
};
