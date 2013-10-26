http://oj.leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //special cases
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *head;
        ListNode *curr;
        
        // head
        if (l1->val > l2->val) { 
            head = l2;
            l2=l2->next;
        }else{
            head = l1;
            l1 = l1->next;
        }
        
        curr = head;
        
        while (l1 && l2)
        {
            if (l1->val > l2->val){
                curr->next = l2;
                l2 = l2->next;
            }else{
                curr->next = l1;
                l1=l1->next;
            }
            
            curr=curr->next;
        }
        
       if (l1) curr->next = l1;
       if (l2) curr->next = l2;
       
       return head;     
    }
};
