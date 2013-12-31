http://oj.leetcode.com/problems/path-sum-ii/
/*
  Question

  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
Discuss


 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> path;
        vector<vector<int>> result;
        pathSumHelper(root, sum, path, result);
        
        return result;
    }
    
    void pathSumHelper(TreeNode *root, int sum, vector<int> path, vector<vector<int>> &result)
    {
        if ( !root ) return;
        
        //visit root
        path.push_back(root->val);
        
        if (!root->left && !root->right && root->val == sum){
            //find one path
            result.push_back(path);
        }else{
            pathSumHelper(root->left,sum-root->val,path,result);
            pathSumHelper(root->right,sum-root->val,path,result);
        }
        
    }
};
