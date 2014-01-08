/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

//Focus: 1. Pay attention to if/else scope.
	 2. Stack operation. stack.push(), v=stack.pop(), stack.empty(), stack.peek()
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
    public ArrayList<Integer> postorderTraversal(TreeNode root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        Stack<TreeNode> stack = new Stack<TreeNode>();
        ArrayList<Integer> res = new ArrayList<Integer>();
        
        TreeNode curr = root;
        while(true){
            if (curr != null){
                if (curr.right !=null) stack.push(curr.right);
                stack.push(curr);
                curr = curr.left;
            }else{
                if (stack.empty()) break;
                curr = stack.pop();
                if (!stack.empty() && curr.right == stack.peek()){
                    stack.pop();
                    stack.push(curr);
                    curr=curr.right;
                }else{
                    res.add(curr.val);
                    curr=null;
                }    
            }
        }
        
        return res;
    }
}
