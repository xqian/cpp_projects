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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( preorder.size() != inorder.size()) return NULL;
        if( preorder.size() == 0) return NULL;
        return buildTree(preorder, 0, inorder, 0, inorder.size());
    }
    
    TreeNode *buildTree(vector<int> &preorder, int start1, vector<int> &inorder, int start2, int sz) {
        if( sz == 0) return NULL;
        if( sz == 1) {
            if ( preorder[start1] == inorder[start2]) {
                return new TreeNode(preorder[start1]);
            }
            else {
                return NULL;
            }
        }
        int t = find(inorder.begin() + start2, inorder.begin() + start2 + sz, preorder[start1]) - inorder.begin();
        if ( t == start2 + sz) return NULL;
        TreeNode * tr = new TreeNode( preorder[start1]);
        int szLeft = t - start2;
        tr -> left = buildTree(preorder, start1+1, inorder, start2, szLeft);
        tr -> right = buildTree(preorder, start1+1+szLeft, inorder, t+1, sz - szLeft -1);
        return tr;
    }
};
