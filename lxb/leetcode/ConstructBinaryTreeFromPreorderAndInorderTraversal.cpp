http://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/*
 Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

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


Method 2: Use array start and length to travel array to avoid one off error.
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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode *helper(vector<int> &preorder, int pstart, int plen, vector<int> &inorder, int istart, int inlen)
    {
        if (plen <= 0 || inlen <= 0) return NULL;
      
        //get root from preorder
        TreeNode *root = new TreeNode(preorder[pstart]);
        
        // find left child length
        int llen = 0;  //left child length
        for (int i=0; i<inlen;++i)
        {
            if (preorder[pstart] != inorder[i+istart]){
                llen++;
            }else{
                break;
            }
        }
        
        int rlen = inlen - llen - 1;  //right child length
        
        root->left = helper(preorder, pstart + 1,llen, inorder, istart, llen);
        root->right = helper(preorder, pstart + llen + 1, rlen, inorder, istart + llen + 1, rlen);
        
        return root;
    }
};
