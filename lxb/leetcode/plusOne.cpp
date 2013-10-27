http://oj.leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result = digits;
        reverse(result.begin(), result.end());
        
        int carrier = 1;
        int sum ;
        for (int i=0; i< result.size(); i++)
        {
            sum = result[i] + carrier;
            if (sum >= 10) {
                carrier = 1;
                result[i] = sum - 10;
            }else{
                result[i] = sum;
                carrier = 0;
                break;
            }
        }
        
        if (carrier == 1){
            result.push_back(1);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
