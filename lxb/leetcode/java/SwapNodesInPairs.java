/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
//Focus: 1. prev,next,dummy node to handle together.   2. null handle.
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
    public ListNode swapPairs(ListNode head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode dummy = new ListNode(0);
        ListNode prev = dummy;
        prev.next=head;
        
        while (head !=null && head.next !=null){
            ListNode next = head.next;
            head.next = next.next;
            next.next = head;
            prev.next = next;
            prev=prev.next.next;
            head=prev.next;
        }
        
        return dummy.next;
    }
}
