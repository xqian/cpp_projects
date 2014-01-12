/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    public int sumNumbers(TreeNode root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return helper(root,0);
    }
    
    private int helper(TreeNode root, int sum){
        if (root == null) return sum;
        if (root.left == null) return helper(root.right, sum * 10 +root.val);
        if (root.right == null) return helper(root.left, sum * 10 +root.val);
        return helper(root.left, sum*10 + root.val) + helper(root.right, sum*10 + root.val);
    }
}
