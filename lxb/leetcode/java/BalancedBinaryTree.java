//Focus: 1. In Java, there is no easy way to return multiple value. (vs c++, it can be done by reference in function).
	 2. Use special value -1 for unbalanced. Post order travel for bottom up.
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
    public boolean isBalanced(TreeNode root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        return getHeight(root) >= 0 ? true: false;
    }
    
    private int getHeight(TreeNode root){
        if (root == null) return 0;
        
        int leftHeight = getHeight(root.left);
        if (leftHeight < 0) return -1;
        
        int rightHeight = getHeight(root.right);
        if (rightHeight < 0) return -1;
        
        if (Math.abs(leftHeight - rightHeight) > 1) return -1;
        
        return Math.max(leftHeight, rightHeight) + 1;
    }
}
