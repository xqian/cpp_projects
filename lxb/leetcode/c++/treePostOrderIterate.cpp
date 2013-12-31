http://oj.leetcode.com/problems/binary-tree-postorder-traversal/

/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode *> S;
        TreeNode *curr = root;
        while(1){
            if (curr) {
                if (curr->right) S.push(curr->right);
                S.push(curr);
                curr = curr->left;
                continue;
            }
            
            if (S.empty()) break;
            
            curr = S.top(); S.pop();
            
            if (curr->right && (!S.empty()) && curr->right == S.top()){
                TreeNode *right = S.top(); S.pop();
                S.push(curr);
                curr = right;
            }else{
                result.push_back(curr->val);
                curr = NULL;
            }
        }
        
        return result;
    }
};
