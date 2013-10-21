http://oj.leetcode.com/submissions/detail/753072/

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        //special case
        if (m == n) return head;
        
        // travel m.
        ListNode *pre, *dummy,*next,*tail;
        dummy = new ListNode(0);
        dummy->next = head;
        pre = dummy;
        
        // find mth node.
        int i = m;
        while( i > 1 ){
            i--;
            pre = pre->next;
            head = head->next;
        }
        
        tail = head;
        // reverse m to n;
        for (int count=m; count <= n;count++){
            next = head->next;
            head->next = pre->next;
            pre->next = head;
            head = next;
            if (!head) break;
        }
        
        //last one.
        tail->next = head;
        
        // return 
        return dummy->next;
    }
};
