http://oj.leetcode.com/submissions/detail/753188/

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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        set<int> S;
        
        if (!head) return head;
        
        ListNode *curr = head;
        ListNode *pre = head;

        while(curr){
            if (S.find(curr->val) == S.end()){
                S.insert(curr->val);
                pre = curr;
                curr = curr->next;
                continue;
            }
            
            pre->next = curr->next;
            delete curr;
            curr = pre->next;
        }
        
        return head;
    }
};
