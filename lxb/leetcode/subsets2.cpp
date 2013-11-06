http://oj.leetcode.com/problems/subsets-ii/
/*Question:
 Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
//method 1: remove duplicate with N (easier, but not very efficient)
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        int N = 1<<S.size();
        for (int i=0; i<N;i++){
            vector<int> oneSet;
            for (int j=0; j< S.size(); j++){
                if (i & (1<<j)) oneSet.push_back(S[j]);
            }
            
            // decide duplicate
            if (!existing(result,oneSet))
                result.push_back(oneSet);
        }
        
        return result;
    }
    
    bool existing(vector<vector<int> > &result, vector<int> oneSet)
    {
        for (int i=0; i< result.size();i++){
            if (result[i].size() == oneSet.size()){
                //equal for every element?
                int j=0;
                for (; j<oneSet.size(); j++){
                    if (result[i][j] != oneSet[j]) break;
                }
                
                if (j==oneSet.size()) return true;
            }
        }
        
        return false;
    }
};

//Method 2
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> path;
        
        subsetsWithDupHelper(S,0,path,result);
        return result;
    }
    
    void subsetsWithDupHelper(const vector<int> &S, int begin, vector<int> &path, vector<vector<int> > &result)
    {
        result.push_back(path);
        
        for (int i=begin; i<S.size();i++){
            //handle duplicate
            if (i>begin && S[i] == S[i-1]) continue;
            
            path.push_back(S[i]);
            subsetsWithDupHelper(S, i+1, path, result);
            path.pop_back();
        }
    }
};

//Method 3: combination classic DFS . Using set to remove duplicate and copy back to vector.

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
      set<vector<int> > resultSet;
      int index = 0;
      vector<int> oneSolution;
      
      sort(S.begin(), S.end());
      
      DFS(S,0, oneSolution, resultSet);
      vector<vector<int> > result(resultSet.begin(), resultSet.end());
      
      return result;
    }
    
    void DFS(vector<int> &S, int index, vector<int> &oneSolution, set<vector<int> > &result)
    {
        // base
        if (index == S.size()) {
            result.insert(oneSolution);
            return;
        }
        
        // either choose it
        oneSolution.push_back(S[index]);
        DFS(S,index+1, oneSolution, result);
        
        //recover
        oneSolution.pop_back();
        
        // or not choose
        DFS(S,index+1, oneSolution, result);
    }
};
