http://oj.leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > result;
        
        for (int i=0; i< numRows; i++){
            vector<int> rowI(i+1);
            rowI[0] = 1;
            rowI[i] = 1;
            
            //populate middle elements
            for (int j=1; j<i; j++){
                rowI[j] = result[i-1][j-1] + result[i-1][j];
            }
            
            result.push_back(rowI);
        }
        
        return result;
    }
};
