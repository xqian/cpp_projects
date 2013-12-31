http://oj.leetcode.com/problems/combination-sum/

/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/
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
