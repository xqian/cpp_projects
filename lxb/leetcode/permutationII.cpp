http://oj.leetcode.com/problems/permutations-ii/
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

Solution: using set to handle duplication.

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > res;
        DFS(res, num ,0);
        return res;
    }
    
    void DFS(vector<vector<int> > &result, vector<int> &num, int d)
    {
        if (d == num.size()-1){
            result.push_back(num);
            return;
        }
        
        //handle dup
        set<int> hash;
        
        for (int index=d; index<num.size(); index++)
        {
            if (hash.find(num[index]) != hash.end()) continue;
            hash.insert(num[index]);
            
            swap(num[index],num[d]);
            DFS(result,num,d+1);
            
            //recover
            swap(num[index],num[d]);
        }
    }
    
    void swap(int &a, int &b)
    {
        int c = a;
        a = b;
        b = c;
    }
};
