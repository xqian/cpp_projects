class Solution {
private:
    static int delta_x[];
    static int delta_y[];
    static int numDirs;
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word.length() == 0) return true;
        size_t m = board.size();
        if ( m == 0) return false;
        size_t n = board[0].size();
        if ( n == 0) return false;
        vector<vector<bool > > visited(m, vector<bool>(n, false));
        for(int i=0; i < m; ++i) {
            for(int j=0; j < n; ++j) {
                if ( search(board, i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isValidRow(int x, vector<vector<char> > &board) {
        return ( x >= 0 && x < board.size());
    }
    
    bool isValidCol(int y, vector<vector<char> > &board) {
        return ( y >=0 && y < board[0].size());
    }
    
    bool search(vector<vector<char> > &board, int x, int y, const string & word, int cur, 
                vector<vector<bool > > &visited) {
        if ( word[cur] == board[x][y]) {
            if ( cur == word.length()-1) return true;
            visited[x][y] = true;
            for(int i=0; i < numDirs; ++i) {
                int n_x = x + delta_x[i];
                int n_y = y + delta_y[i];//BUG TYPO x + delta_y
                if ( isValidRow(n_x, board) && isValidCol(n_y, board)) {
                    if (!visited[n_x][n_y] && search(board, n_x, n_y, word, cur+1, visited) ) { //BUG: missing visited
                        return true;
                    }
                }
            }
            visited[x][y] = false;
        }
        return false;
    }
};

    int Solution::delta_x[] = {-1, 0, 1, 0};
    int Solution::delta_y[] = {0, 1, 0, -1};
    int Solution::numDirs = sizeof(delta_x)/sizeof(int);
