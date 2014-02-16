/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return helper(inorder, 0 , inorder.length - 1, postorder, 0, postorder.length - 1);
    }
    
    private TreeNode helper(int[] inorder, int istart, int iend, int[] postorder, int pstart, int pend) {
        if (pstart > pend) {
            return null;
        }
        
        TreeNode root = new TreeNode(postorder[pend]);
        
        //find root index in inorder
        int index = istart;
        for (; index <= iend; ++index) {
            if (inorder[index] == postorder[pend])
                break;
        }
        
        int left_child_len = index - istart;
        int right_child_len = iend - index;
        
        root.left = helper(inorder, istart, istart + left_child_len - 1,
                            postorder, pstart, pstart + left_child_len - 1);
        root.right = helper(inorder, istart + left_child_len + 1, iend,
                            postorder, pstart + left_child_len, pend - 1);
                            
        return root;
    }
}
