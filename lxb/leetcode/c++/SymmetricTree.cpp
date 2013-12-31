http://oj.leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        queue<TreeNode *> l, r;
        
        // special cases
        if (!root) return true;
        if (!root->left && !root->right) return true;
        
        l.push(root->left); r.push(root->right);
        
        while(!l.empty() && !r.empty()){
            //get left,right node
            TreeNode *left = l.front(); l.pop();
            TreeNode *right = r.front(); r.pop();
            
            if (!left && !right) continue;
            if (!left || !right) return false;
            
            // if not equal return false
            if (left->val != right->val) return false;
            
            // enque :l(left->right) , rQueue(right->left)
            l.push(left->left);l.push(left->right);
            r.push(right->right);r.push(right->left);
        }
        
        // if both empty, return true,otherwise false.
        if (l.empty() && r.empty()) return true;
        
        return false;
    }
};
