http://oj.leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<int> result(rowIndex+1);
        vector<int> lastRow(rowIndex+1);
        
        for (int i=0; i<=rowIndex; i++){
            lastRow = result;
            result[0] = 1;
            result[i] = 1;
            
            //populate the middle range
            for (int j=1; j < i; j++){
                result[j] = lastRow[j-1] + lastRow[j]; 
            }
        }
        
        return result;
    }
};
