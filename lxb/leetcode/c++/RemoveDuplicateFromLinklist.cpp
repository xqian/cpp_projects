http://oj.leetcode.com/submissions/detail/753188/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

Method 0: qsort partition idea. Two pointer, p0, maintain the value uniq, copy value if properly.
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode *p0 = head;
        ListNode *p1 = head->next;
        
        //trick: idea from qsort pilot
        while(p1){
            if (p0->val != p1->val){
                p0=p0->next;
                p0->val = p1->val;
            }
            p1=p1->next;
        }
        
        //now remove all node after p0 (not included)
        if (!p0->next) return head;
        
        ListNode *toDelete = p0->next;
        p0->next = NULL;
        
        while (toDelete){
            ListNode *tmp = toDelete;
            toDelete = toDelete->next;
            delete tmp;
        }
        
        return head;
    }
};

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
