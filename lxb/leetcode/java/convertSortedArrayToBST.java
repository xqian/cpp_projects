/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

//Focus: 1. use start, end to identify sub array.

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
    public TreeNode sortedArrayToBST(int[] num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return buildTree(num, 0, num.length-1);
    }
    
    private TreeNode buildTree(int[] num, int start, int end){
        if (start > end) return null;
        if (start == end) return (new TreeNode(num[start]));
        
        int mid = start + (end - start)/2;
        TreeNode root = new TreeNode(num[mid]);
        root.left = buildTree(num, start, mid-1);
        root.right = buildTree(num, mid+1, end);
        return root;
    }
}
