http://oj.leetcode.com/submissions/detail/751367/

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
