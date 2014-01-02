/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//Focus: write fast and correct and complete.
	2. use helper function
public class Solution {
    public boolean isSymmetric(TreeNode root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (root == null) return true;
        return isSymmetric(root.left, root.right);
    }
    
    private boolean isSymmetric(TreeNode t1, TreeNode t2)
    {
        if (t1==null && t2 == null) return true;
        if (t1==null || t2 == null) return false;
        
        return t1.val == t2.val && isSymmetric(t1.left,t2.right) && isSymmetric(t1.right, t2.left);
    }
}
