/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTreeHelper(preorder, 0 , preorder.length - 1, inorder, 0, inorder.length - 1);
    }
    
    private TreeNode buildTreeHelper(int[] preorder, int pstart, int pend, int[] inorder, int istart, int iend) {
        if (pstart > pend) return null;
        TreeNode root = new TreeNode(preorder[pstart]);
        
        //find location in inorder
        int inorder_index = istart;
        for (; inorder_index <= iend; ++inorder_index) {
            if (inorder[inorder_index] == preorder[pstart]) {
                break;
            }
        }
        
        int left_child_len = inorder_index - istart;
        int right_child_len = iend - inorder_index;
        
        root.left = buildTreeHelper(preorder, pstart + 1, pstart + left_child_len, 
                                    inorder, istart, istart + left_child_len);
        
        root.right = buildTreeHelper(preorder, pstart + left_child_len + 1, pend, 
                                    inorder, istart + left_child_len + 1, iend);
                                    
        return root;
    }
}
