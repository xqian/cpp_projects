http://oj.leetcode.com/problems/wildcard-matching/

/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

Method 1: Recursive, timeout.   From https://github.com/soulmachine/leetcode

Submission Result: Time Limit Exceeded
Last executed input:	"abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (*p == '\0') return (*s == '\0');
        
        if (*p != '*'){
            if (*s == *p || *p =='?' && *s != '\0') return isMatch(s+1,p+1);
            return false;
        }else{
            while (*p == '*') p++;  //skip continous '*'
            if (*p == '\0') return true;
            
            while (*s != '\0' && !isMatch(s,p)) ++s;
            
            return *s != '\0';
        }
    }
};
