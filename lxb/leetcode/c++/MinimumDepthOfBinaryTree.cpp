http://oj.leetcode.com/problems/minimum-depth-of-binary-tree/

/* Question:
  Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (!root) return 0;
        
        return minDepthHelper(root);
    }
    
    int minDepthHelper(TreeNode *root){
        if (!root->left && !root->right) return 1;
        
        if (!root->left) return minDepthHelper(root->right) + 1;
        if (!root->right) return minDepthHelper(root->left) + 1;
        
        int lh = minDepthHelper(root->left);
        int rh = minDepthHelper(root->right);
        
        //min heigh
        return lh>rh?rh+1:lh+1;
    }
};
