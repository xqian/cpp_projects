
Focus:  1. Understand the question first. Rotate, not reverse!!
	2. Have algorithm ready before coding.
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int n) {
        // find list length
        int len = 0;
        ListNode curr = head;
        while(curr != null) {
            curr = curr.next;
            len++;
        }
        
        if (len == 0) return head;
        
        n = n % len;
        if (n == 0) return head;
        
        // divide len into two section. n and len - n
        // find the end node of left part with length len-n.
        int leftNum = len - n;
        curr = head;
        ListNode prev = head;
        while (leftNum > 0) {
            prev = curr;
            curr = curr.next;
            leftNum--;
        }
        
        //now curr is the new head
        ListNode oldHead = head;
        prev.next = null;
        head = curr;
        
        while (curr.next != null) {
            curr = curr.next;
        }
        
        curr.next = oldHead;
        
        return head;
    }
}
