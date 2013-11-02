http://oj.leetcode.com/problems/binary-tree-maximum-path-sum/

/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

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
    int maxPathSum(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;
        
        int csum=0;
        int summax=INT_MIN;
        maxPathSumHelper(root, csum, summax);
        
        return summax;
    }
    
    void maxPathSumHelper(TreeNode *root, int &csum, int &summax){
        if (!root){
            csum = 0;
            return;
        }
        
        int lsum = 0;
        int rsum = 0;
        
        maxPathSumHelper(root->left,lsum,summax);
        maxPathSumHelper(root->right,rsum,summax);
        
        csum = lsum>rsum?lsum+root->val:rsum+root->val;
        csum = csum>root->val?csum:root->val;
        summax = max(max(summax, csum), lsum+rsum+root->val);
    }
};
