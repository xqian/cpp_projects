http://oj.leetcode.com/problems/sudoku-solver/

/*Question
 Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
 */

Solution: 1. check sudoku validation, with specific position.

class Solution {
public:
    bool solveSudoku(vector<vector<char> > &board) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int N = board.size();
        for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
        {
            if (board[row][col] == '.'){
                for (int i=1; i<=9; i++)
                {
                    board[row][col] = i + '0';
                    if (isValidSudoku(board, row, col) && solveSudoku(board)) return true;
                    board[row][col] = '.';
                }
                return false;
            }
        }
        
        return true;
    }
    
private:
    bool isValidSudoku(vector<vector<char> > &board, int row, int col) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        //check row
        for (int i=0; i<board.size(); i++)
        {
            if (i!=row && board[i][col] == board[row][col]) return false;
        }
        
        //check col
        for (int j=0; j<board.size(); j++){
            if (j!=col && board[row][j] == board[row][col]) return false;
        }
        
        //check 
        for (int i=3* (row/3); i< 3*(row/3 + 1); i++)
        for (int j=3*(col/3); j<3*(col/3+1); j++)
        {
            if (i!=row && j!=col && board[i][j] == board[row][col]) return false;
        }
        
        return true;
    }
};
