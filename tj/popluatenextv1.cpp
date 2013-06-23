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
            TreeLinkNode * headNext = headCurLevel -> left;
            if( headNext == NULL) break;
            TreeLinkNode * p = headCurLevel;
            TreeLinkNode * q = headNext;
            
            if ( p -> right != NULL) {
                q -> next = p -> right;
                q = q -> next;
            }
            else {
                q -> next = NULL;
                break;
            }
            p = p -> next;
            while( p != NULL) {
                if ( p -> left != NULL) {
                    q -> next = p -> left;
                    q = q-> next;
                }
                else {
                    q -> next = NULL;
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
            q -> next = NULL; //ALMOST MISS it
            headCurLevel = headNext;
        }
    }
};