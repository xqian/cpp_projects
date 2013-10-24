http://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (preorder.size() == 0) return NULL;
        
        return buildTreeHelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    
    TreeNode *buildTreeHelper(vector<int> &preorder, int pstart, int pend, vector<int>&inorder, int istart, int iend){
        // base
        if (pstart > pend || istart > iend) return NULL;
        if (pstart == pend || istart == iend) return (new TreeNode(preorder[pstart]));
        
        TreeNode *root = new TreeNode(preorder[pstart]);
        
        //find left child number in preorder
        int leftChildCount = 0;
        for (int i = istart; i<=iend; i++ ){
            if (inorder[i] != preorder[pstart]) leftChildCount++;
            else break;
        }
        
        //recursively build left child tree and right child tree
        root->left = buildTreeHelper(preorder, pstart+1,pstart+leftChildCount,inorder,istart,istart+leftChildCount-1);
        root->right = buildTreeHelper(preorder,pstart+leftChildCount+1, pend, inorder, istart+leftChildCount+1, iend);
        
        return root;
    }
};
