http://oj.leetcode.com/submissions/detail/751367/

/*
 Question:

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head || k<=1 ) return head;
        
        stack<ListNode *> S;
        ListNode *curr=head;
        ListNode *tail = NULL;
        
        while (curr){
            //push into stack every k nodes
            int i = 1;
            ListNode *begin = curr;
            for (; i<=k;i++){
                S.push(curr);
                curr= curr->next;
                if (!curr) break;
            }
            
            // last section.
            if (i < k ){
                // handle last segment, don't reverse, just connect.
                if (tail)  tail->next = begin;
                return head;
            }
            
            //reverse them by insert into tail.
            while (!S.empty()){
                if (!tail){
                    tail = S.top();
                    head = tail;
                }else{
                    tail->next = S.top();
                    tail = tail->next;
                }
            
                S.pop();
            }
            
            tail->next = NULL;
            
        }
        
        return head;
    }
};
