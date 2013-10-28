http://oj.leetcode.com/problems/word-search/

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
