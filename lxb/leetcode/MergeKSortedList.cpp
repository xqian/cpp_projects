http://oj.leetcode.com/problems/merge-k-sorted-lists/

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
    struct Node{
        int index;
        ListNode *ln;
        
        Node(int i,ListNode* l):index(i),ln(l){};
    };
    
    struct compare{
        bool operator()(const Node &l, const Node &r){
            return l.ln->val > r.ln->val;
        }
    };
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        priority_queue<Node, vector<Node>, compare>   PQ;
        
        // init PQ
        for (int i=0; i < lists.size(); i++){
            if (lists[i])   {
                ListNode *tmp = lists[i];
                lists[i] = lists[i]->next;
                tmp->next = NULL;
                PQ.push(Node(i, tmp));
            }
        }
        
        // get from Q, insert into merged list. move original list to next;

        ListNode *result = NULL;
        ListNode *tail = NULL;
        while (!PQ.empty())
        {
            //get one from PQ
            ListNode *node=PQ.top().ln;
            int nextListIndex = PQ.top().index;
            PQ.pop();
        
            //insert it into result.
            if (tail == NULL){
                tail = node;
                result = tail;
            }else{
                tail->next = node;
                tail = node;
            }
        
            //refill one into PQ 
            if (lists[nextListIndex]){
                ListNode *tmp = lists[nextListIndex];
                lists[nextListIndex] = lists[nextListIndex]->next;
                tmp->next = NULL;
            
                //insert into PQ
                PQ.push(Node(nextListIndex, tmp));
            }
        }
        
        return result;
    }
};
