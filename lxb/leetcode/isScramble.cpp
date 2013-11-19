http://oj.leetcode.com/problems/scramble-string/
Issue: Very hard. Here is the DFS solution brute force, but inefficient and timeout.

Submission Result: Time Limit Exceeded
Last executed input:	"abcdefghijklmn", "efghijklmncadb"

/* Question:
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (s1.size() != s2.size()) return false;
        if (s1.empty()) return true;
        
        if (s1.size() == 1) return s1==s2;
        
        for (int i=1; i<s1.size();i++)
        {
            string s1_left = s1.substr(0,i);
            string s1_right = s1.substr(i,s1.size()-i);
            string s2_left1 = s2.substr(0,i);
            string s2_right1 = s2.substr(i,s2.size()-i);
            string s2_left2 = s2.substr(0,s2.size()-i);
            string s2_right2 = s2.substr(s2.size()-i,i);
            
            if ( ( isScramble(s1_left, s2_left1) && isScramble(s1_right,s2_right1)) ||
                 ( isScramble(s1_left, s2_right2) && isScramble(s1_right,s2_left2)))
                 return true;
        }
        
        return false;
    }
};
