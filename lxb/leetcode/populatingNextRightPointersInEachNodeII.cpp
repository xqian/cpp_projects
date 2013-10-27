http://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (!root) return ;
        
        queue<TreeLinkNode *> Q;
        Q.push(root);
        
        while (!Q.empty()){
            int oneLevelSize = Q.size();
            
            //travel this level
            TreeLinkNode *prev = NULL;
            TreeLinkNode *curr;
            for (int i=0; i< oneLevelSize; i++){
                curr = Q.front();
                Q.pop();
                
                //put children into queue
                if (curr->left) Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
                
                //adjust next pointer
                if (!prev) prev = curr;
                else {
                    prev->next = curr;
                    prev = curr;
                }
            }
            prev->next = NULL;
        }
        
    }
};
