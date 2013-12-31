http://oj.leetcode.com/problems/zigzag-conversion/

Question:
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int nRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (s.size() < 2) return s;
        if (nRows < 2) return s;
        
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
                    else break;
                }
            }
        }
        
        return ret;
    }
};

// version 0: if nRows = 1,it will fail
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
