http://oj.leetcode.com/problems/recover-binary-search-tree/
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
    void recoverTree(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return;
        
        vector<TreeNode* > L;
        inorder(root,L);
        
        int a=0, b=0;
        for(int i=0;i < L.size()-1; i++){
            if (L[i]->val > L[i+1]->val) {
                a = i;
                break;
            }
        }
        
        for (int j=L.size()-1; j>a;j--){
            if (L[j]->val < L[j-1]->val){
                b = j;
                break;
            }
        }
        
        //swap a, b
        int tmp = L[a]->val;
        L[a]->val = L[b]->val;
        L[b]->val = tmp;
    }
    
    void inorder(TreeNode *root, vector<TreeNode *> &L){
        if (!root) return;
        inorder(root->left,L);
        L.push_back(root);
        inorder(root->right,L);
    }
};
