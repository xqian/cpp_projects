http://oj.leetcode.com/problems/word-search/

Method 1: DFS recursive. boundary check.
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool> > visited(row, vector<bool>(col,false));
        
        for (int i=0; i < row; i++)
        for (int j=0; j < col; j++)
        {
            if (board[i][j] == word[0]){
                if (DFS(board,word,0,i,j,visited)) return true;
            }
        }
        
        return false;
    }
    
    bool DFS(vector<vector<char> > &board, string &word, int index, int r, int c, vector<vector<bool> > &visited)
    {
        if (board[r][c] != word[index] || visited[r][c]) return false;
        if (index == word.size()-1) return true;
        
        visited[r][c] = true;
        
        if (r > 0 && DFS(board, word, index+1, r-1,c,visited)) return true;
        if (r < board.size()-1  && DFS(board, word, index+1, r+1, c, visited)) return true;
        if (c > 0 && DFS(board, word, index+1, r, c-1, visited)) return true;
        if (c < board[0].size()-1 && DFS(board, word, index+1, r, c+1, visited)) return true;
        
        visited[r][c] = false;
        return false;
    }
};

Method 2: 1. check boundary in a function and makes code neat.
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
    
        const int m = board.size();
        const int n = board[0].size();
        
        vector<vector<bool> > visited(m,vector<bool>(n,false));  
        
        for (int row=0; row<m; row++)
        for (int col=0; col<n; col++)
        {
            if ( board[row][col] == word[0] && DFS(board, word, 0, row, col, visited) ) return true;
        }
        
        return false;
    }
    
    bool isValidMove(int row, int col, int M, int N)
    {
        if (row<0 || row >=M || col < 0 || col >= N) return false;
        
        return true;
    }
    
    bool DFS(vector<vector<char> > &board, const string &word, int index, int row, int col, vector<vector<bool> > &visited)
    {
        if (!isValidMove(row,col, board.size(), board[0].size()) || board[row][col] != word[index] || visited[row][col])
            return false;
        
        //find one solution  //Pay attention to OneOff error.
        if (index == word.size()-1) return true;
        
        //mark visited
        visited[row][col] = true;
        
        if (DFS(board, word, index+1, row-1, col, visited) ||
           DFS(board, word, index+1, row, col-1,visited) ||
           DFS(board, word, index+1, row+1, col, visited) || 
           DFS(board, word, index+1, row, col+1, visited)) return true;
        
        //recovery
        visited[row][col] = false;
        
        return false;
    }
};
