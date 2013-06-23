//Actually this version is not better than previous one

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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root == NULL) return; //BUG miss it
        TreeLinkNode * headCurLevel = root;
        root->next = NULL;
        while( headCurLevel != NULL) {
            TreeLinkNode * headNext = NULL;
            TreeLinkNode * p = headCurLevel;
            TreeLinkNode * q = headNext;
            
            while( p != NULL) {
                if ( p -> left != NULL) {
                    if( headNext == NULL) {
                        headNext = p -> left;
                        q = headNext;
                    }
                    else
                    {
                        q -> next = p -> left;
                        q = q-> next;
                    }
                }
                else {
                    if ( q != NULL) {       //BUG, miss it
                        q -> next = NULL;
                    }
                    break;
                }
                if ( p -> right != NULL) {
                    q -> next = p -> right;
                    q = q -> next;
                 }
                else {
                    q -> next = NULL;
                    break;
                }
                p = p -> next; //NOTICE: almost miss it
            } 
            if ( q != NULL) { //BUG miss it
                q -> next = NULL; //ALMOST MISS it
            }
            headCurLevel = headNext;
        }
    }
};