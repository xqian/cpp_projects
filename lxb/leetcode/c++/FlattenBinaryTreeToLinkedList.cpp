http://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/

/*
 Question

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return ;
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        if (left){
            root->right = left;
            root->left = NULL;
            
            TreeNode *leftMostRight = left;
            while (leftMostRight->right) leftMostRight=leftMostRight->right;
            leftMostRight->right=right;
        }
        
        flatten(root->right);
    }
};
