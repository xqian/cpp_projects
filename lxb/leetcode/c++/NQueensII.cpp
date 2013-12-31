http://oj.leetcode.com/problems/n-queens-ii/

/*
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.
*/

Solution: 1. DFS
	  2. strange: vector can't pass large test, but dynamic array can.


class Solution {
public:
    int totalNQueens(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int res = 0;
        int *A = new int[n];
        
        DFS(A, res, n, 0);
        delete[] A;
        return res;
    }
    
    void DFS(int A[], int &res, int n, int curr)
    {
        if (curr == n){
            res++;
            return;
        }
        
        for (int i=0; i<n; i++)
        {
            A[curr] = i;
            if (isValid(A,curr)){
                DFS(A,res,n,curr+1);
            }
        }
    }
    
    bool isValid(int A[], int curr)
    {
        for (int i=0; i<curr; i++)
        {
            if (A[i]==A[curr] || abs(A[i] - A[curr]) == curr - i)  return false;
        }
        
        return true;
    }
};
