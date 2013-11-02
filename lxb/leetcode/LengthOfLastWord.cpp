http://oj.leetcode.com/problems/length-of-last-word/

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //special case
        if (!s || *s=='\0') return 0;
        
        const char *ptr = s;
        
        // find last character
        while(*ptr != '\0') ptr++;
        ptr--;
        
        // find last string
        while (*ptr == ' ' && ptr >= s) ptr--;
        if (ptr<s) return 0;
        
        int count = 0;
        while (*ptr != ' '){
            count++;
            ptr--;
            if (ptr<s) break;
        }
        
        return count;
    }
};
