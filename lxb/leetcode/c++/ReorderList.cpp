http://oj.leetcode.com/problems/reorder-list/
/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        // handle 0,1,2 node
        if (!head || !head->next || !head->next->next) return;
        
        // find the middle element
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev;
        
        while (fast && fast->next){
            prev=slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // handle odd/even middle node.
        if (fast) prev=slow;   //else: one node ahead of slow. 
        
        //reverse the latter part.
        ListNode *curr=prev->next;
        prev->next=NULL;
        while(curr){
            ListNode *next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr=next;
        }
        
        //merge
        ListNode *reversedPart = prev->next;
        prev->next = NULL;
        
        while(head && reversedPart){
            ListNode *tmp = head->next;
            head->next = reversedPart;
            reversedPart = reversedPart->next;
            head->next->next = tmp;
            head = tmp;
        }
        
        return;
    }
};
