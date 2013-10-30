Note: It passed 23 test cases, but failed on
Input:	[[-7],[-2,1],[-5,-5,9],[-4,-5,4,4],[-6,-6,2,-1,-5],[3,7,8,-3,7,-9],[-9,-1,-9,6,9,0,7],[-7,0,-6,-8,7,1,-4,9],[-3,2,-6,-9,-7,-6,-9,4,0],[-8,-6,-3,-9,-2,-6,7,-5,0,7],[-9,-1,-2,4,-2,4,4,-1,2,-5,5],[1,1,-6,1,-2,-4,4,-2,6,-6,0,6],[-3,-3,-6,-2,-6,-2,7,-9,-5,-7,-5,5,1]]
Output:	-69
Expected:	-63

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = triangle.size();
        if (n == 0) return 0;
        if (n == 1) return triangle[0][0];
        
        // define S[i,j] : the minimum path sum including element triangle[i][j]
        // S[i,j] = min(S[i-1,j-1], S[i-1,j],S[i-1,j+1]) + triangle[i][j]  , pay attention to boundary
        // init: S[0][0] = triangle[0][0]
        vector<vector<int> > S(n, vector<int>(n,INT_MAX));
        S[0][0] = triangle[0][0];
        
        for (int row=1; row < n; row++)
        for (int col=0; col < triangle[row].size(); col++)
        {
            //S[i,j] = min(S[i-1,j-1], S[i-1,j],S[i-1,j+1]) + triangle[i][j]  
            
            if (col < row ) S[row][col] = S[row-1][col];
            if (col>0 && S[row-1][col-1] < S[row][col]) S[row][col] = S[row-1][col-1];
            if (col<row-2 && S[row-1][col+1] < S[row][col]) S[row][col] = S[row-1][col+1];
            S[row][col] += triangle[row][col];
        }
        
        // find the mininum from last row
        int minSum = INT_MAX;
        for (int i=0; i<n; i++){
            if (S[n-1][i] < minSum)
                minSum = S[n-1][i];
        }
        
        return minSum;
    }
};
