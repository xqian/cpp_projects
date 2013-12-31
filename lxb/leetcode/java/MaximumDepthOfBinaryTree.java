//Focus:  1.  Java Tree definition. No pointer as C++. :-) and reference. root.left
//	  2.  Math.max
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
    public int maxDepth(TreeNode root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (root == null) return 0;
        
        return Math.max(maxDepth(root.left),maxDepth(root.right)) + 1;
        
    }
}
