http://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (inorder.size() == 0) return NULL;
        
        return buildTreeHelper(inorder, 0 ,inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode *buildTreeHelper(vector<int> &inorder, int istart, int iend, vector<int> &postorder, int pstart, int pend){
        if (istart == iend || pstart == pend) return new TreeNode(inorder[istart]);
        if (istart > iend || pstart > pend) return NULL;
        
        //root is postorder[pend]
        TreeNode *root = new TreeNode(postorder[pend]);
        
        // count left child tree node.
        int numLeftChild = 0;
        for (int i = istart; i<=iend; i++){
            if (inorder[i] != postorder[pend]) numLeftChild++;
            else break;
        }
        
        // now build left,right child recursively
        root->left = buildTreeHelper(inorder, istart, istart + numLeftChild - 1, postorder, pstart,pstart+numLeftChild-1);
        root->right = buildTreeHelper(inorder, istart + numLeftChild+1, iend, postorder, pstart + numLeftChild,pend-1);
        
        return root;
    }
};
