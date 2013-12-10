http://oj.leetcode.com/problems/combination-sum-ii/
/*
Question:
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

Method 2: use set to remove duplicate.
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(num.begin(),num.end());
        
        set<vector<int> > results;
        vector<int> oneResult;
        
        dfs(num, results,oneResult,target,0);
        vector<vector<int> > res(results.begin(),results.end());
        return res;
    }
    
private:
    void dfs(vector<int> &num, set<vector<int> > &results, vector<int> &oneResult, int gap, int index)
    {
        if (gap == 0){
            results.insert(oneResult);
            return;
        }
        
        if (index == num.size()) return;
        
        // cut branch
        if (num[index] > gap) return;
        
        // choose it.
        oneResult.push_back(num[index]);
        dfs(num,results,oneResult,gap-num[index],index+1);
        
        // or not choose it.
        oneResult.pop_back();
        dfs(num, results, oneResult, gap, index+1);
    }
};


class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        sort(num.begin(),num.end());
        
        vector<vector<int> > results;
        vector<int> oneResult;
        
        dfs(num, results,oneResult,target,0);
        return results;
    }
    
private:
    void dfs(vector<int> &num, vector<vector<int> > &results, vector<int> &oneResult, int gap, int index)
    {
        if (gap == 0){
            
            if (!existing(results, oneResult)) results.push_back(oneResult); //todo: duplicate?
            return;
        }
        
        if (index == num.size()) return;
        
        // cut branch
        if (num[index] > gap) return;
        
        // choose it.
        oneResult.push_back(num[index]);
        dfs(num,results,oneResult,gap-num[index],index+1);
        
        // or not choose it.
        oneResult.pop_back();
        dfs(num, results, oneResult, gap, index+1);
    }
    
    bool existing(vector<vector<int> > &result, vector<int> &oneResult){
        for (int i=0; i<result.size(); i++){
            if (result[i].size() == oneResult.size()){
                int j = 0;
                for (; j<oneResult.size(); j++){
                    if (oneResult[j] != result[i][j]) break;
                }
                
                if (j==oneResult.size()) return true;
            }
        }
        
        return false;
    }
};
