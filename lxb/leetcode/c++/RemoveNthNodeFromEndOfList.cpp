http://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/

/*
 Question
 Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head) return NULL;
        
        //n==0
        if (n==0) return head;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        //fast move n step first.
        while (fast && n > 0) {
            n--;
            fast=fast->next;
        }
        
        //n > L
        if (n>0) return head;
        
        ListNode *pre;
        while(fast) {
            pre=slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        // n == L
        if (slow == head){
            head = head->next;
            delete slow;
            return head;
        }
        
        // delete nth
        pre->next = slow->next;
        delete slow;
        
        return head;
    }
};
