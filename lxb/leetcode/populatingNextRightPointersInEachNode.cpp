http://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if (!root) return;
        
        queue<TreeLinkNode *> Q;
        Q.push(root);
        
        while (!Q.empty())
        {
            int size = Q.size();
            
            TreeLinkNode *pre = NULL;
            for (int i=0; i<size; i++){
                TreeLinkNode *curr = Q.front();
                Q.pop();
                
                if (!pre) pre = curr;
                else { pre->next = curr; pre = curr;}
                
                if (curr->left) Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
            }
        }
        
    }
};
