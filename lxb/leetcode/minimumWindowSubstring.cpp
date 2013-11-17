http://oj.leetcode.com/problems/minimum-window-substring/

/*Q:
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

Solution: Two pointer:begin, end. Move end until we find a window. Then shrink window by moving beginning and check whether we can't move further.

class Solution {
public:
    string minWindow(string S, string T) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        //special case
        if (S.empty()) return "";
        if (S.size() < T.size()) return "";
        
        //hash counter.
        const int ASCII_NUM = 256;
        vector<int> expected(ASCII_NUM, 0);  // from T
        vector<int> actual(ASCII_NUM, 0);    
        
        int totalExpectedNum = 0;
        for (auto c:T){
            expected[c]++;
            totalExpectedNum++;
        }
        
        //two pointers
        int begin = 0;
        int end = 0;
        
        //result
        int minWidth = INT_MAX;
        int minBegin = 0;
        
        int found = 0;
        while (end < S.size()){
            if (expected[S[end]] > 0){
                if (actual[S[end]] < expected[S[end]]){
                    found++;
                }
                
                actual[S[end]]++;
            }
            
            if (found == totalExpectedNum){
                
                //shrink first pointer
                while (expected[S[begin]]==0 || actual[S[begin]] > expected[S[begin]]){
                    if (expected[S[begin]] > 0)
                        actual[S[begin]]--;
                    begin++;
                }
                
                if (minWidth > end-begin + 1){
                    minBegin = begin;
                    minWidth = end - begin + 1;
                } 
                
                //Move to next round;
                actual[S[begin]]--;
                begin++;
                found--;
            }
            
            end++;
        }
        
        if (minWidth == INT_MAX) return "";
        
        return S.substr(minBegin, minWidth);
        
    }
};
