/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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

Focus:  1. Specail case handle first.
	2. move tail pointer properly.
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        
        int overflow = 0;
        ListNode l3 = null;
        ListNode tail = null;
        while (l1 != null && l2 != null) {
            int val = l1.val + l2.val + overflow;
            overflow = val / 10;
            val = val % 10;

            ListNode node = new ListNode(val);
            if (l3 == null) {
                l3 = node;
                tail = node;
            } else {
                tail.next = node;
            }
        }
        
        while (l1 != null) {
            int val = l1.val + overflow;
            overflow = val / 10;
            val = val % 10;
            tail.next = new ListNode(val);
        }
        
        while (l2 != null) {
            int val = l2.val + overflow;
            overflow = val / 10;
            val = val % 10;
            tail.next = new ListNode(val);
        }
        
        if (overflow != 0) {
            tail.next = new ListNode(overflow);
        }
        
        return l3;
    }
}
