http://oj.leetcode.com/problems/interleaving-string/
/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.  
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        
        if (len1 == 0) return s2 == s3;
        if (len2 == 0) return s1 == s3;
        
        if (len1 + len2 != len3) return false;
        
        // DP[i][j] means whether str1(1..i) and str2(1..j) can interleve with str3(1..i+j);
        // state transition:
        // if str1[i] == str3[i+j] DP[i][j] = DP[i-1][j] || DP[i][j]
        // if str2[j] == str3[i+j] DP[i][j] = DP[i][j-1] || DP[i][j]
        // 
        vector<vector<bool> > DP(len1 + 1, vector<bool>(len2+1, false) );
        
        //init
        for (int i=1; i<=len1; i++)
        {
            if (s1[i-1] == s3[i-1]) {
                DP[i][0] = true;
            }else{
                //not match
                break;
            }
        }
        
        for (int j=1; j<=len2; j++){
            if (s2[j-1] == s3[j-1]){
                DP[0][j] = true;
            }else{
                break;
            }
        }
        
        //DP
        for (int i=1; i< len1+1; i++)
        {
            for (int j=1; j< len2+1; j++)
            {
                if (s2[j-1] == s3[i+j-1]){
                    DP[i][j] = DP[i][j-1] || DP[i][j];
                }
            
                if (s1[i-1] == s3[i+j-1]){
                    DP[i][j] = DP[i-1][j] || DP[i][j];
                }
            }
        }
        
        return DP[len1][len2];
    }
};
