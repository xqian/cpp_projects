http://oj.leetcode.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        map<int,int> S;
        for (int i=0;i<n;i++){
            if (S.find(A[i]) == S.end())  S[A[i]] = 1; 
            else S[A[i]]++;
        }
        
        for (int i=0; i<n;i++){
            if (S[A[i]] == 1) return A[i];
        }
        
    }
};
