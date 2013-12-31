http://oj.leetcode.com/problems/generate-parentheses/

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        string s="";
        generateParenthesisHelper(result,0,0,n,s);
        return result;
    }
    
    void generateParenthesisHelper(vector<string> &result, int l, int r, int n, string s){
        //base:
        if (l+r == n + n){
            result.push_back(s);
            return;
        }
        
        // "(" if "(" left
        if (l < n)  generateParenthesisHelper(result,l+1,r,n,s+"(");
        if (l > r)  generateParenthesisHelper(result,l,r+1,n,s+")");
    }
};
