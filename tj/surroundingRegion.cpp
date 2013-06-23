class Solution {
    
private:
    const static int delta_x[];
    const static int delta_y[];
    const static int numDirs;
    
    enum {
        Surrounding = 'X',
        Surrounded = 'O',
        Permanant = 'P',
        Visited = 'V'
    };
    
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        size_t m = board.size();
        if ( m == 0) return;
        size_t n = board[0].size();
        if ( n == 0) return;
        
        for(int i = 0; i < m; ++i) {
            for(int j=0; j < n; ++j) {
                if ( board[i][j] == Surrounded) {
                    bfs(board, i * n + j);
                }
            }
        }
        
        for(int i = 0; i < m; ++i) {
            for(int j=0; j < n; ++j) {
                if ( board[i][j] == Permanant) {
                    board[i][j] = Surrounded;
                }
                
            }
        }
    }
    
    
    void bfs(vector<vector<char>> &board, int cur) {
        int n = board[0].size();
        vector<int> va;
        va.push_back(cur);
        int i = 0;
        while ( i < va.size()) {
            int x = va[i] / n;
            int y = va[i] % n;
            for( int j = 0; j < numDirs; ++j) {
                int n_x = x + delta_x[j];
                int n_y = y + delta_y[j];
                if ( isValid(board, n_x, n_y) ){
                    if ( board[n_x][n_y] == 'P') {
                        mark(board, va, 'P');
                        return;
                    }
                    else if ( board[n_x][n_y] == 'O') {
                        board[n_x][n_y] = 'V';
                        va.push_back( n_x * n + n_y);
                    }
                }
                else {
                    mark(board, va, 'P');
                    return;
                }
            }
            i++;
        }
        mark(board, va, 'X');        
    }
    
    bool isValid(vector<vector<char>> &board, int x, int y) {
        if (  x < 0  || x >= board.size()) return false;
        if ( y <0 || y >= board[0].size()) return false;
        return true;
    }
    
    void mark(vector<vector<char>> &board, const vector<int> & va, char ch) {
        for(int i=0; i < va.size(); ++i) {
            int x = va[i] / board[0].size();
            int y = va[i] % board[0].size();
            
            board[x][y] = ch;
        }
    }
};

const    int Solution::delta_x[] = {-1, 0, 1, 0};
const    int Solution::delta_y[] = {0, 1, 0, -1};
const    int Solution::numDirs = sizeof(delta_x)/sizeof(int);
    
