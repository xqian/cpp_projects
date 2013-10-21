http://oj.leetcode.com/submissions/detail/745641/

class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (n == 0 ) return 0;
        if (n == 1) return 1;
        if (n==2) return 2;
        
        
        vector<int> S(n+1);
        S[0] = 0;
        S[1] = 1;
        S[2] = 2;
        
        for (int i=2;i < n ;i++){
            S[i+1] = S[i-1] + S[i];
        }
        
        return S[n];
        
    }
};
