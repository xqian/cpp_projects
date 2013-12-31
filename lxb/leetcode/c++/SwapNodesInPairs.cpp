http://oj.leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head || !head->next) return head;
        
        ListNode *dummy, *pre, *next;
        
        dummy = new ListNode(0);
        dummy->next = head;
        pre = dummy;
        
        while(head){
            next = head->next;
            
            if (!next) return dummy->next;
            
            head->next = next->next;
            next->next = head;
            head = head->next;
            pre->next = next;
            pre = next->next;
        }
        
        return dummy->next;
    }
};
