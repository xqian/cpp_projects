http://oj.leetcode.com/submissions/detail/716750/

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
    bool isValidBST(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return isValidBSTHelper(root,INT_MIN,INT_MAX);
    }
    
    bool isValidBSTHelper(TreeNode *root, int low, int high){
        if (!root) return true;
        
        if (root->val <= low || root->val >= high) return false;
        
        return isValidBSTHelper(root->left, low, root->val) && isValidBSTHelper(root->right, root->val, high);
    }
};
