http://oj.leetcode.com/problems/valid-sudoku/
/*
 Question:
 etermine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


 */


class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

        int n = board.size();
        assert(n==9);
        
        //check row
        for (int row = 0; row<n; row++)
        {
            vector<bool> R(n,false);
            for (int col = 0; col<n; col++)
            {
                if (board[row][col] == '.') continue;
                if (R[board[row][col]-'1'] == true ) return false;
                R[board[row][col] - '1'] = true;
            }
        }
        
        //check col
        for (int col = 0; col<n; col++)
        {
            vector<bool> C(n,false);
            for (int row = 0; row<n; row++)
            {
                if (board[row][col] == '.') continue;
                if (C[board[row][col]-'1'] == true ) return false;
                C[board[row][col]-'1'] = true;
            }
        }
        
        // check grid
        for (int i=0; i<n; i+=3)
        {
            for (int m=0; m<n; m+= 3){
                vector<bool> G(9,false);
                for (int j=i; j<i+3;j++)
                {
                    for (int k=m; k<m+3;k++){
                        if (board[j][k] == '.') continue;
                
                        if (G[board[j][k] - '1'] == true) return false;
                        G[board[j][k] - '1'] = true;
                    }
                }
            }
        }
        
        return true;
    }
};
