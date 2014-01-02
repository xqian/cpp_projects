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
    public ArrayList<Integer> preorderTraversal(TreeNode root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ArrayList<Integer> res = new ArrayList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode curr = root;
        
        while(true){
            if (curr != null){
                res.add(curr.val);
                if (curr.right != null) stack.add(curr.right);
                curr = curr.left;
                continue;
            }
            
            if (stack.empty()) break;
            curr = stack.pop();
        }
        
        return res;
    }
}
