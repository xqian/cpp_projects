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

Method 2:
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        
        vector<int> path;
        vector<vector<int> > res;
        dfs(S,path,res,0);
        return res;
    }
    
private:
    void dfs(vector<int> &S, vector<int> &path, vector<vector<int> >&res, int index){
        res.push_back(path);
         
        //ext:
        for (int i=index; i<S.size(); ++i){
            //TODO: dup handle.
            // if (i > index && S[i] == S[i-1]) continue;
            
            path.push_back(S[i]);
            dfs(S,path,res,i+1);
            path.pop_back();
        }
    }
};
