http://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/

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
