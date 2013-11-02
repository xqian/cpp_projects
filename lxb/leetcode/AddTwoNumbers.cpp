http://oj.leetcode.com/problems/add-two-numbers/

/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Discuss


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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!l1) return l2;
        if (!l2) return l1;
        
        int carrier = 0;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while(l1 && l2){
            int sum = l1->val + l2->val + carrier;
            if (sum >= 10) {
                carrier =1;
                sum -= 10;
            }
            else    carrier = 0;
            ListNode *newNode = new ListNode(sum);
            
            if (!head){
              head = newNode;
              tail = newNode;
            } else{
                tail->next = newNode;
                tail = newNode;
            }
            //move pointer
            l1 = l1->next;
            l2 = l2->next;
            
        }
        
        while(l1){
            int sum = l1->val + carrier;
            if (sum>=10) {
                carrier=1;
                sum -= 10;
            }else{
                carrier = 0;
            }
            
            tail->next = new ListNode(sum);
            tail = tail->next;
            
            l1 = l1->next;
        }
        
        while(l2){
            int sum = l2->val + carrier;
            if (sum>=10) {
                carrier=1;
                sum -= 10;
            }else{
                carrier = 0;
            }
            
            tail->next = new ListNode(sum);
            tail = tail->next;
            l2 = l2->next;
        }
        
        //last bit
        if (carrier){
            tail->next = new ListNode(1);
        }
        
        return head;
    }
};
