http://oj.leetcode.com/problems/partition-list/

/* Question:
 Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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
    ListNode *partition(ListNode *head, int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (!head || !head->next) return head;
        
        ListNode *LessThanList = NULL;
        ListNode *GreaterEqualList = NULL;
        ListNode *l1 = NULL;
        ListNode *l2 = NULL;
        
        while(head){
            if ( head->val < x ){
                //insert l1.
                if (!l1) {
                    l1 = head;
                    LessThanList = l1;
                }else{
                    l1->next = head;
                    l1=l1->next;
                }
            }else{
                if (!l2) {
                    l2 = head;
                    GreaterEqualList = l2;
                }else{
                    l2->next = head;
                    l2 = l2->next;
                }
            }
            
            head = head->next;
        }
        
        if (!LessThanList) return GreaterEqualList;
        if (!GreaterEqualList) return LessThanList;
        
        l2->next = NULL;
        l1->next = GreaterEqualList;
        
        return LessThanList;
    }
};
