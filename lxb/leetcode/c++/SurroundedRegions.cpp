http://oj.leetcode.com/problems/surrounded-regions/
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        //Always check boundary or special case.
        if (board.size() == 0) return; 
        
        int row = board.size();
        int col = board[0].size();
        
        // scan 4 borders
        for (int i=0; i< row; i++){
            if (board[0][i] == 'O') { DFS(board, 0,i);}
        }
        
        for (int i=0; i< row; i++){
            if (board[row-1][i] == 'O') { DFS(board, row-1,i);}
        }
        
        for (int i=0; i< col;i++){
            if (board[i][0] == 'O') { DFS(board, i,0);}
        }
        
        for (int i=0; i< col; i++){
            if (board[i][col-1] == 'O') {DFS(board, i,col-1);}
        }
            
        // now change all O to X.
        for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
        {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == '#') board[i][j] = 'O';
        }
    }
    
    void DFS(vector<vector<char> > &board, int i, int j){
        board[i][j] = '#';
        if (i>=1 && board[i-1][j] == 'O') DFS(board,i-1,j);
        
        if (i<board.size()-1 && board[i+1][j] == 'O') DFS(board,i+1,j);
        
        if (j>=1 && board[i][j-1] == 'O') DFS(board,i,j-1);
        
        if (j<board[0].size()-1 && board[i][j+1] == 'O') DFS(board,i,j+1);
    }
};
