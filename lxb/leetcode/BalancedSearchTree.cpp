http://oj.leetcode.com/problems/balanced-binary-tree/

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
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return true;
        
        int h=0;
        return isBalancedHelper(root,h);
    }
    
    bool isBalancedHelper(TreeNode *root,int &h)
    {
        if (!root) {
            h = 0;
            return true;
        }
        
        int lh,rh ;
        if (! isBalancedHelper(root->left, lh)) return false;
        if (! isBalancedHelper(root->right, rh)) return false;
        
        // not balanced
        if (lh-rh>1 || rh-lh>1){
            return false;
        }
        
        // get height
        h = lh>rh ?lh+1:rh+1;
    
        return true;
    }
};
