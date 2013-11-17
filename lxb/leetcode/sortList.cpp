http://oj.leetcode.com/problems/sort-list/

/*Question
  Sort a linked list in O(n log n) time using constant space complexity.
 */

Solution: 1. merge sort.  2. two pointer tech.

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
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (!head || !head->next) return head;
        
        //merge sort
        //split
        ListNode *faster = head->next;
        ListNode *slow = head;
        
        while(faster && faster->next){
            slow = slow->next;
            faster = faster->next->next;
        }
        
        ListNode *list1 = head;
        ListNode *list2 = slow->next;
        slow->next = NULL;
        
        list1 = sortList(list1);
        list2 = sortList(list2);
   
        head = mergeList(list1, list2); 
        
        return head;
    }
    
private:
    ListNode * mergeList(ListNode *list1, ListNode *list2)
    {
        //special case
        if (!list1) return list2;
        if (!list2) return list1;
        
        //merge
        ListNode *head = NULL;
        ListNode *curr = NULL;
        
        while (list1 && list2)
        {
            if (list1->val < list2->val){
                if (!curr){
                    curr=list1;
                    head = curr;
                }else{
                    //insert into tail
                    curr->next = list1;
                    curr=curr->next;
                }
                
                list1 = list1->next;
                curr->next = NULL;
            }else{
                if (!curr){
                    curr = list2;
                    head = curr;
                }else{
                    curr->next = list2;
                    curr=curr->next;
                }
                list2 = list2->next;
                curr->next=NULL;
            }
        }
        
        if (list1) curr->next = list1;
        if (list2) curr->next = list2;
        
        return head;
    }
};
