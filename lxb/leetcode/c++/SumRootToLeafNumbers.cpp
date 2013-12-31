http://oj.leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbers(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (!root) return 0;
        
        int sum = 0;
        sumNumberHelper(root,0, sum);
        
        return sum;
    }
    
    void sumNumberHelper(TreeNode *root, int s, int &sum){
        if (!root->left && !root->right) {
            //find one path
            sum += s*10+root->val;
            return;
        }
            
        
        if (root->left) sumNumberHelper(root->left,s*10+root->val,sum);
        if (root->right) sumNumberHelper(root->right,s*10+root->val,sum);
        
        return;
    }
};
