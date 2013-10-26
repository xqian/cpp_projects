http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
        
        if (!head || !head->next) return head;
        
        ListNode *dummy = new ListNode(-1);
        
        // first round, count times
        unordered_map<int,int> hashTable;
        ListNode *curr = head;
        while(curr){
            if (hashTable.find(curr->val) == hashTable.end()) {
                hashTable[curr->val] = 1;
            }else{
                hashTable[curr->val]++;
            }
            
            curr = curr->next;
        }
        
        //second round, delete
        ListNode *pre = dummy;
        while(head){
            if (hashTable[head->val] > 1){
                //delete it.
                pre->next = head->next;
                delete head;
                head = pre->next;
            }else{
                pre->next = head;
                pre = head;
                head = head->next;
            }
        }
        
        return dummy->next;
    }
};
