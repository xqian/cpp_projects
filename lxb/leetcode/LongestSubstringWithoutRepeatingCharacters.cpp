http://oj.leetcode.com/problems/longest-substring-without-repeating-characters/

/*question:
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;
        
        //eg:  abcbdac    
        int maxLen = 0;
        int end = 0;
        int begin = 0;
        bool R[256] = {false};
        
        for (; end<s.size(); end++){
            if (R[s[end]]){
                if (maxLen < (end-begin) )   maxLen = end -begin;
            
                //reset  j..i
                while (s[begin] != s[end]){
                    R[s[begin]] = false;
                    begin++;
                }
                begin++;
            }else   R[s[end]] = true;
        }
        
        // last compare
        maxLen = max(maxLen, end-begin);
        
        return maxLen;
    }
};
