http://oj.leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > result;
        vector<int> intermediate;
        dfs(candidates,target,intermediate,result,0);
        return result;
    }
    
    void dfs(vector<int> &candidates, int gap, vector<int> &intermediate, vector<vector<int> > &result, int index)
    {
        if (gap==0){
            result.push_back(intermediate);
            return;
        }
        
        for (int i=index; i<candidates.size(); i++){
            if (candidates[i] > gap) return;
            
            intermediate.push_back(candidates[i]);
            dfs(candidates,gap-candidates[i], intermediate, result, i);
            intermediate.pop_back();
        }
    }
};
