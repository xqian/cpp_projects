http://oj.leetcode.com/problems/n-queens/
/*Question:
 The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

Solution: 1. classic DFS.
	  2. condition: A[i] = j means putting queen onto row i, col j
	  3. A[curr] != A[i] && (curr - i) != (abs(A[curr] - A[i]) != abs(curr - i)


class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<vector<string> > res;
        vector<int> A(n,-1);
        DFS(res, A, 0, n);
        return res;
    }
    
    void DFS(vector<vector<string> > &res, vector<int> &A, int curr, int n)
    {
        if (curr == n)
        {
            vector<string> sol;
            for (auto r: A)
            {
                string temp(n,'.');
                temp[r] = 'Q';
                sol.push_back(temp);
            }
            res.push_back(sol);
            return;
        }
        
        for (int i=0; i<n; i++)
        {
            A[curr] = i;
            
            if (isValid(A,curr)){
                DFS(res, A, curr+1, n);
            }
        }
    }
    
    bool isValid(vector<int> &A, int r)
    {
        for (int i=0; i<r; i++)
        {
            if (A[i] == A[r] || abs(A[i]-A[r]) == abs(i-r)) return false;
        }
        
        return true;
    }
};
