/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

Focus: 1. String s, s.length(), s.charAt(1), s.substring(startIndex, endIndex)
       2. expand with center.

public class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
        String res = "";
        for (int i=0; i<len; i++){
            String ps = getPalindrome(s, i, i);
            if (ps.length() > res.length()) 
                res = ps;
                
            if (i>=1 && s.charAt(i) == s.charAt(i-1)){
                ps = getPalindrome(s, i-1, i);
                if (ps.length() > res.length()) 
                    res = ps;
            }
        }
        
        return res;
    }
    
    private String getPalindrome(String s, int l, int r){
        while (l>=0 && r < s.length() && s.charAt(l) == s.charAt(r))
        {
            l--;
            r++;
        }
        
        return s.substring(l+1,r);
    }
}
