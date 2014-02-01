/* Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Discuss

*/
Focus:  1. Java pass by value!! so you can't get first/second TreeNode pass into function and get back value.
	   That's a reason I used global variable. (But bad practice?)
	2. Using recursive to find out mismatch. Pay attention to second.
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
    TreeNode prev = null;
    TreeNode first = null;
    TreeNode second = null;
        
    public void recoverTree(TreeNode root) {
        findWrongNode(root);
        
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }
    
    private void findWrongNode(TreeNode root) {
        if (root == null) {
            return;
        }
        
        findWrongNode(root.left);
        
        if (prev != null && prev.val > root.val) {
            if (first == null) {
                first = prev;
            }  
            second = root;
        }
        
        prev = root;
        findWrongNode(root.right);
    }
}
