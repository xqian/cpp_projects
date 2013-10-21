http://oj.leetcode.com/problems/palindrome-number/submissions/

class Solution {
public:
    bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (x<0) return false;
        
        int n = 1;
        while (x/n >= 10) n*=10;
        
        while(x){
            int l = x/n;
            int r = x%10;
            if (l != r) return false;
            
            x = x%n / 10;
            n = n / 100;
        }
        
        return true;
    }
};
