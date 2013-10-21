
http://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head) return NULL;
        
        ListNode *start=head;
        ListNode *end=head;
        while(end->next) end=end->next;
        return sortedListToBSTHelper(start,end);
        
    }
    
    TreeNode* sortedListToBSTHelper(ListNode *start, ListNode *end)
    {
        // find middle node
        ListNode *slow = start;
        ListNode *fast = start;
        
        while(fast && fast!=end && fast->next && fast->next != end){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        // now slow is the middle.
        TreeNode *root = new TreeNode(slow->val);
        
        //single element.
        if (start == end) return root;
        
        // rebuild left child
        ListNode *leftUpper = start;
        while (leftUpper!=slow && leftUpper->next != slow)  leftUpper=leftUpper->next;
        
        if (leftUpper != slow){
            root->left = sortedListToBSTHelper(start, leftUpper);
        }
        
        // rebuild right child
        root->right = sortedListToBSTHelper(slow->next, end);
        
        return root;
    }
};
