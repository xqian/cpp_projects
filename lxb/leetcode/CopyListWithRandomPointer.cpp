http://oj.leetcode.com/problems/copy-list-with-random-pointer/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (!head) return NULL;
        
        // copy and build node.
        RandomListNode *first = head;
        
        while (first){
            RandomListNode *newNode = new RandomListNode(first->label);
            newNode->next = first->next;
            first->next = newNode;
            first = first->next->next;
        }
        
        // copy random link
        first = head;
        while(first){
            if (first->random){
                first->next->random = first->random->next;
            }else{
                first->next->random = NULL;
            }
            first=first->next->next;
        }
        
        // restore next link
        first=head;
        RandomListNode *copyList = first->next;
        RandomListNode *copy = copyList;
        while(first){
            copy = first->next;
            first->next = copy->next;
            first = first->next;
            
            // handle last node.
            if (first)  copy->next = first->next;
        }
        
        return copyList;
    }
};
