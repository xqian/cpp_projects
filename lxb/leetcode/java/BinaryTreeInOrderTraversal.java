/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Discuss

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
//Focus: 1. Stack usage.  Stack<T> s = new Stack<T>(); s.add(a); s.pop(); s.empty();
	 2. ArrayList<T> usage. ArrayList<T> al = new ArrayList<T>(); al.add(a); 

public class Solution {
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ArrayList<Integer> res = new ArrayList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode curr = root;
        
        while(true){
            if (curr != null){
                stack.add(curr);
                curr = curr.left;
                continue;
            }
            
            if (stack.empty()) break;
            curr = stack.pop();
            res.add(curr.val);
            curr = curr.right;
        }
        
        return res;
    }
}
