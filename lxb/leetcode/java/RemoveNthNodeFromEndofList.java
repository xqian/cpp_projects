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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        ListNode fast = head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        while (fast!=null && n>0){
            fast=fast.next;
            n--;
        }
        
        if (n > 0) return head;
        
        ListNode slow = dummy;
        
        while (fast !=null){
            slow=slow.next;
            fast=fast.next;
        }
        
        slow.next=slow.next.next;
        
        return dummy.next;
    }
}
