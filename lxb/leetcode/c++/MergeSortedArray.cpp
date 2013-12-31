http://oj.leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int a = m-1;
        int b = n-1;
        int k = m+n-1;
        
        while(a>=0 && b>=0) A[k--] = (A[a] > B[b]) ? A[a--]:B[b--];
        
        while(b>=0) A[k--] = B[b--];
    }
};
