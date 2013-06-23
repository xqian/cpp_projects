//NOTICE: linked list prone off by one bug, use examples!!!
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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( k == 0) return head;
        if ( head == NULL) return NULL;
        int steps = 0;
        ListNode * p = head;
        while( p != NULL && steps != k) {
            p = p->next;
            steps++;
        }
        if ( p == NULL) {
            k = k % steps;
            if ( k == 0) return head;
            p = head;
            steps = 0;
            while( steps != k) {
                p = p->next;
                steps++;
            }
        }                
        ListNode *preNewHead = head;

        while(p->next != NULL) {
            preNewHead = preNewHead->next;
            p = p->next;
        }
        p->next = head;
        ListNode *newHead = preNewHead ->next;
        preNewHead ->next = NULL;
        return newHead;
    }
};