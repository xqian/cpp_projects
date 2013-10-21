http://oj.leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        // find array size
        int N =strs.size();
        int d=0; //position
        
        if (N==0) return "";

        while(1){
            // start from 0, compare each string, if all same, continue, otherwise find one. if any string ended, find one
            char ch = strs[0][d];
            for (int i=0; i< N; i++){
                if (strs[i][d] == '\0' || strs[i][d] != ch){
                    if (d==0)  return "";
                    else return strs[i].substr(0,d);
                }
            }
                
            d++;
        }
    }
};
