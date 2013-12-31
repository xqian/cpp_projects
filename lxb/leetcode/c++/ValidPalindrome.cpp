http://oj.leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s[0] == '\0') return true;
        
        int start = 0;
        int end = s.length()-1;
        
        while (start <= end){
            if (!isalnum(s[start]))    {
                start++;
                continue;
            }
            
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            
            if (toupper(s[start]) != toupper(s[end])) return false;
            start++;
            end--;
        }
        
        return true;
    }
};
