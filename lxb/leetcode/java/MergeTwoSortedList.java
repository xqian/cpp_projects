/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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

//Focus: 1. dummy head.  2. last node.
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        while(l1!=null && l2!=null){
            if (l1.val < l2.val){
                curr.next=l1;
                curr = curr.next;
                l1=l1.next;
            }else{
                curr.next=l2;
                curr = curr.next;
                l2=l2.next;
            }
        }
        
        while(l1!=null){
            curr.next=l1;
            l1=l1.next;
            curr=curr.next;
        }
        
        while (l2!=null){
            curr.next=l2;
            l2=l2.next;
            curr=curr.next;
        }
        
        curr.next=null;
        
        return dummy.next;
    }
}
