http://oj.leetcode.com/problems/pascals-triangle-ii/
/*Question:
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

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
