http://oj.leetcode.com/problems/recover-binary-search-tree/

/*
Question

  Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
