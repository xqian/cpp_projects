http://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*Question
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/
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
