Issue: Not passed,
http://oj.leetcode.com/problems/palindrome-partitioning-ii/

Runtime Error: Last executed input:	"ab"

class Solution {
public:
    int minCut(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s.size() <2) return 0;
        
        int n = s.size();
        vector<int> DP(n+1);  //(DP[i] means:min cut for str in (i..n-1) )
        for (int i=0; i<n; i--){
            DP[i] = n - i;
        }
        
        //if s[i..j] is palindrom, return true;
        vector<bool> f(n,false);
        vector<vector<bool> > isPal(s.size(),f);
        for (int i=0; i<n;i++) isPal[i][i] = true;
        
        //for (int i=0; i<n-1;i++) if (s[i] == s[i+1]) isPal[i][i+1] = true;
        
        //DP 
        for (int j=n-1; j>=0; j--)
        for (int k =j; k<n;k++){
            if (s[j] == s[k] && (k-j<2 || isPal[j+1][k-1])){
                isPal[j][k] = true;
                DP[j] = min(DP[j], 1 + DP[k+1]);
            }
        }
        
        return DP[0]-1;
    }
};
