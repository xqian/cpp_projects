/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

//Focus: 1. two pointer. When meet, fast == slow.

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
    public boolean hasCycle(ListNode head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        ListNode fast = head;
        ListNode slow = head;
        
        while(fast !=null && fast.next != null){
            fast = fast.next.next;
            slow=slow.next;
            
            if (fast == slow) break;
        }
        
        return !(fast==null || fast.next == null);
        
    }
}
