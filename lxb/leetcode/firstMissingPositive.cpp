http://oj.leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for (int i=0; i<n; i++){
            while(A[i] != i+1 && A[i]<=n && A[i] >0 && A[i] != A[A[i]-1]){
                int c = A[A[i]-1];
                A[A[i]-1] = A[i];
                A[i] = c;
            }
        }
        
        //check A[i] = i-1. If not, it's the first one.
        for (int i = 0; i<n; i++){
            if ( A[i] != i+1 ) return i+1;
        }
        
        return n+1;
    }
};
