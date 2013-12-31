http://oj.leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();
        
        //special case
        if (M == 0) return 0;
        if (obstacleGrid[0][0] == 1) return 0;
        
        // init to S[i,j] = 0
        vector<vector<int> > S(M, vector<int>(N,0));
                
        S[0][0] = 1;
        //base
        for (int i=1; i<M; i++) {
            if (obstacleGrid[i][0]==0) S[i][0] = 1;
            else break;
        }
        
        for (int col =1; col <N; col++){
            if (obstacleGrid[0][col] == 0) S[0][col] = 1;
            else break;
        }
        
        //DP.
        for (int i=1; i <M; i++)
        for (int j=1; j <N; j++){
            if (obstacleGrid[i][j] == 0){
                S[i][j] = S[i-1][j] + S[i][j-1];
            }else{
                S[i][j] = 0;
            }
        }
        
        return S[M-1][N-1];
    }
};
