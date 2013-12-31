http://oj.leetcode.com/submissions/detail/753072/

/*
Question

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* Method 2:*/
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (!head) return NULL;

	//special case
	if (m == n) return head;
        
        //find mth and m-1th.
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy;
        
        // Pay attention to one-off error
        // 1. find mth [1..m)
        int index = 1;
        while (head && index<m)
        {
            prev = head;
            head = head->next;
            index++;
        }
        
        // Now reverse m..n
        // 2. n is included: [m..n]
        ListNode *tail = head;
        while (head && index <= n)
        {
            ListNode *next = head->next;
            head->next = prev->next;
            prev->next = head;
            head = next;
            index++;
        }
       

        if (tail != head)   tail->next = head; 
        
        return dummy.next;
    }
};

// Method 1:
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
