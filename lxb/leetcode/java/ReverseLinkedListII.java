/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/
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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (m == n) return head;
        
        // part 1: 1..m-1
        ListNode curr = head;
        
        // tip: dummy node.
        ListNode prev = new ListNode(0); 
        for (int i = 1; i < m ;++i) {
            prev = curr;
            curr = curr.next;
        }
        
        // part 2: m..n  reverse
        ListNode next = null;
        ListNode last = curr;
        for (int j = m; j <= n; ++j) {
            next = curr.next;
            curr.next = prev.next;
            prev.next = curr;
            curr = next;
        }
        
        // part 3: n..
        last.next = curr;
        
        if (m == 1) head = prev.next;
        
        return head;
    }
}
