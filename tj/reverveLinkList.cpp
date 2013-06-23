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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( m == n) return head;
        ListNode * preStart = head;
        ListNode * start;
        if ( m > 1) {
            for(int i=0; i < m-2; ++i) { //BUG: off by one i < m-1
                preStart = preStart->next;
            }
            start = preStart->next;
        }
        else {
            start = head;
        }
        ListNode * p = reverse(start, n - m);
        if ( m > 1) {
            preStart ->next = p;
            return head;
        }
        else {
            return p;
        }
    }
    
    //Not including start, num items
    ListNode * reverse(ListNode * start, int num) {
        ListNode * pre = start;
        ListNode * cur = start->next;
        ListNode * next = cur->next;
        
        for(int i=1; i <= num; ++i) {
            cur->next = pre;
            pre = cur;
            cur = next;
            if ( cur != NULL) {
                next = cur ->next;    
            }
            else {
                break;
            } 
        }
        start->next = cur;//BUG: start->next = next;!!!
        return pre;
    }
};