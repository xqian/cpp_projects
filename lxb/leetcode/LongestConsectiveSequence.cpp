http://oj.leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (num.size() == 0) return 0;
        
        sort(num.begin(),num.end());
        
        int length = 1;
        int maxLen = 1;
        for (int i=1; i< num.size(); i++){
            //allow duplicate
            if (num[i] == num[i-1]) continue;
            
            if (num[i]-num[i-1] == 1){
                length++;
                continue;
            }else{
                if (length > maxLen){
                    maxLen = length;
                }
                length=1;
            }
        }
        
        return maxLen>length?maxLen:length;
        
    }
};
