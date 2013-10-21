http://oj.leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        // define queue to handle level
        queue<TreeNode *> Q;
        vector<vector<int>> result;
        
        if (!root) return result;
        
        Q.push(root);
        
        // while queue not empty
        while (!Q.empty()){
            // q.size() is on the same level
            int size = Q.size();
            
            vector<int> oneLevelResult;
            
            for (int i=0;i<size;i++){
                TreeNode *curr = Q.front();
                Q.pop();
                oneLevelResult.push_back(curr->val);
                
                if (curr->left) Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
            }
            
            result.push_back(oneLevelResult);
        }
        
        return result;
    }
};
