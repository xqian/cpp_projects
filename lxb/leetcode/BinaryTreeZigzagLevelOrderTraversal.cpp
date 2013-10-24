http://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        
        if (!root) return result;
        
        stack<TreeNode*> S1;
        stack<TreeNode*> S2;
        
        S1.push(root);
        bool oddLevel = true;
        
        while(!S1.empty()){
            int size = S1.size();
            vector<int> oneLevelResult;
            for (int i=0; i< size; i++){
                TreeNode *curr = S1.top();
                S1.pop();
                oneLevelResult.push_back(curr->val);
                if (oddLevel){
                    if (curr->left) S2.push(curr->left);
                    if (curr->right) S2.push(curr->right);
                }else{
                    if (curr->right) S2.push(curr->right);
                    if (curr->left) S2.push(curr->left);
                }
            }
                
            oddLevel = !oddLevel;
            result.push_back(oneLevelResult);
            
            //swap S1 and S2
            S1.swap(S2);
        }
        
        return result;
    }
};
