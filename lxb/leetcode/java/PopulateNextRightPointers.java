/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
//Focus: 1. Queue usage. Queue<T> queue = new LinkedList<T>(); queue.isEmpty(), queue.add(T), queue.remove(), queue.size()
public class Solution {
    public void connect(TreeLinkNode root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (root == null) return;
        
        Queue<TreeLinkNode> queue = new LinkedList<TreeLinkNode>();
        queue.add(root);
        
        while(!queue.isEmpty()){
            int levelSize = queue.size();
            TreeLinkNode prev = null;
            for (int i=0; i<levelSize;++i){
                TreeLinkNode node = queue.remove();
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
                
                if (prev == null) prev = node;
                else {
                    prev.next = node;
                    prev = node;
                }
            }
            prev.next = null;
        }
    }
}
