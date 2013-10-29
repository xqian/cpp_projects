http://oj.leetcode.com/problems/zigzag-conversion/

Note:  Memory Limit Exceeded

class Solution {
public:
    string convert(string s, int nRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (s.size() < 2) return s;
        
        int zigzag_len = nRows * 2 - 2;
        string ret = "";
        
        for (int i=0; i<nRows; i++){
            for (int base = i;base < s.size() ;base += zigzag_len)
            {
                // first/last row
                ret.append(1,s[base]);
                // middle
                if (i > 0 && i < nRows - 1) {
                    int n = base + zigzag_len - 2*i;
                    if (n < s.size())   ret.append(1,s[n]);  
                }
            }
        }
        
        return ret;
    }
};
