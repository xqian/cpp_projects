http://oj.leetcode.com/problems/insertion-sort-list/

/* Question
 * Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (!head || !head->next) return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        
        while(head){
            ListNode *next = head->next;
            
            //insertion sort
            ListNode *curr = dummy.next;
            ListNode *prev = &dummy;
            while(curr && curr->val <= head->val && curr != head){
                prev = curr;
                curr = curr->next;
            }
            
            if (curr != head){
                prev->next = head;
                head->next = curr;
                
                while(curr && curr->next != head) curr=curr->next;
                if (curr) curr->next = NULL;
            }
            
            head = next;
        }
        
        return dummy.next;
        
    }
};
