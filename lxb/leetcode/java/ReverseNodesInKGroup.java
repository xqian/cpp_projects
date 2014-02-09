/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

Focus:  1. Stack<ListNode> stack stack.push(f) stack.pop() stack.empty() stack.size()
	2. dummy node to handle boundary case.
	3. Todo: implement with recursively.

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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k <= 1) return head;
        
        Stack<ListNode> stack = new Stack<ListNode>();
        ListNode dummy = new ListNode(0);
        ListNode curr = head;
        ListNode tail = dummy;
        
        while (curr != null) {
            head = curr;
            
            //put k into stack
            for (int i = 0; i < k; ++i) {
                if (curr != null) {
                    stack.push(curr);
                    curr = curr.next;
                } else {
                    break;
                }
            }
            
            //last group
            if (stack.size() < k) {
                tail.next = head;
                break;
            } else {
                while (!stack.empty()) {
                    tail.next = stack.pop();
                    tail = tail.next;
                }
                tail.next = null;
            }
        }
        
        return dummy.next;
    }
}
