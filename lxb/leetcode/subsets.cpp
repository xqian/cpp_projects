http://oj.leetcode.com/problems/subsets/
/*Question:
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        
        vector<vector<int> > result;
        int N = 1<<S.size();
        
        for (int i=0; i<N; i++){
            // if that bit is 1, choose it.
            vector<int> oneSet;
            for (int j=0; j<S.size();j++){
                if ( i & (1<<j) ) oneSet.push_back(S[j]);
            }
            
            result.push_back(oneSet);
        }
        
        return result;
    }
};
