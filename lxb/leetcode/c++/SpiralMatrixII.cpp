http://oj.leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int start = 0;
        int end = n-1;
        int num = 1;
        
        vector<vector<int> > M(n,vector<int>(n));

        while (start < end){
            //top
            for (int i=start; i< end; i++) M[start][i] = num++;
            
            //right
            for (int j=start; j < end; j++)   M[j][end] = num++;
            
            //bottom
            for (int k=end; k>start; k--) M[end][k] = num++; 
            
            //left
            for (int m=end; m>start; m--) M[m][start] = num++;
            
            start++;
            end--;
        }
        
        // Last element
        if (start == end)   M[start][end] = num;
        
        return M;
    }
};
