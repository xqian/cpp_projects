http://oj.leetcode.com/submissions/detail/724934/

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
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        stack<TreeNode*> S;

        TreeNode *curr = root;
        
        while(1){
            if (curr)  {
                S.push(curr);
                curr=curr->left;
                continue;
            }
            
            //end
            if (S.empty()) break;
            
            //left most node,visit it.
            curr = S.top();
            S.pop();
            result.push_back(curr->val);
            
            // move to right child
            if (curr->right) curr = curr->right;
            else curr = NULL;
        }
        
        return result;
    }
};
