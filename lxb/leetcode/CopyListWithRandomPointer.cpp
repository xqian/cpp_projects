http://oj.leetcode.com/problems/copy-list-with-random-pointer/

/*
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

Method 1: recursive, suitable for interview. O(n) extra space.
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    typedef RandomListNode Node;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
       if (!head) return NULL;
       map<Node *, Node *> mapTable;
       return cloneList(head,mapTable);
    };
    
    Node* cloneList(Node *head,map<Node *, Node *> &mapTable){
        if (!head) return NULL;
        
        if (mapTable.find(head) != mapTable.end()) return mapTable[head];
        
        //clone it and recursively set link
        mapTable[head] = new Node(head->label);
        mapTable[head]->next = cloneList(head->next,mapTable);
        mapTable[head]->random = cloneList(head->random,mapTable);
        
        return mapTable[head];
    }
};

Method 2: O(1) extra space.
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
