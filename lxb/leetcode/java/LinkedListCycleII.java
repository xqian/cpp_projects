/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        //Two pointers
        ListNode fast = head;
        ListNode slow = head;
        
        while (fast !=null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) break;
        }
        
        // case 1: non cycle
        if (fast == null || fast.next == null) return null;
        
        // case 2: cycle, find cycle head;
        fast = head;
        while(fast!=slow){
            fast = fast.next;
            slow = slow.next;
        }
        
        return slow;
    }
}
