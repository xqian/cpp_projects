http://oj.leetcode.com/problems/word-break/
Question:
/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

Discuss


*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s.size() ==0) return true;
        
        vector<bool> DP(s.size()+1,false);
        DP[0] = true;
        
        for (int i=1; i<=s.size();i++){
            for (int j =0; j<i;j++){
                if (DP[j] && (dict.find(s.substr(j,i-j)) != dict.end()) ){
                    DP[i] = true;
                    break;
                }
            }
        }
        
        return DP[s.size()];
        
        
    }
};
