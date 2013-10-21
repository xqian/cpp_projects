http://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return ;
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        if (left){
            root->right = left;
            root->left = NULL;
            
            TreeNode *leftMostRight = left;
            while (leftMostRight->right) leftMostRight=leftMostRight->right;
            leftMostRight->right=right;
        }
        
        flatten(root->right);
    }
};
