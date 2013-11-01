http://oj.leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head || head->next == head) return head;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while ( fast && fast->next ){
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) break;
        }
        
        if (!fast || !fast->next) return NULL;
        
        assert(fast == slow);
        
        slow = head;
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};
