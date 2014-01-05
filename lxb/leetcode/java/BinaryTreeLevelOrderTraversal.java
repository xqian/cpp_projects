/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

//Focus: 1. Queue is an interface in Java. (but Stack is a class in java). LinkedList implemented it.
	 2. Queue init: Queue<Integer> Q = new LinkedList<Integer>();
	 3. method: Q.add(12);  Integer elem = Q.remove()  Q.isEmpty() Q.size()

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
    public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if (root == null) return res;
        
        Queue<TreeNode> Q = new LinkedList<TreeNode>();
        Q.add(root);
        
        while (!Q.isEmpty()){
            int levelSize = Q.size();
            ArrayList<Integer> oneLevel = new ArrayList<Integer>();
            for (int i=0; i<levelSize; ++i){
                TreeNode curr = Q.remove();
                if (curr.left != null) Q.add(curr.left);
                if (curr.right != null) Q.add(curr.right);
                oneLevel.add(curr.val);
            }
            
            res.add(oneLevel);
        }
        
        return res;
    }
}
