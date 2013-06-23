/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 //More general case but it looks cleaner
 //Old way is faster (slightly) for complete BT
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( root == NULL) return;
        TreeLinkNode * curHead = root;
        while( curHead != NULL) {
            TreeLinkNode * nextHead = NULL;
            TreeLinkNode * p = findNextHead(curHead, nextHead);
            if( p == NULL) break;
            TreeLinkNode * q = nextHead;
            if ( p -> left == nextHead && p -> right != NULL) {
                q -> next = p ->right;
                q = q->next;
            }
            p = p -> next;
            while( p!= NULL) {
                if ( p -> left != NULL) {
                    q -> next = p -> left;
                    q = q -> next;
                }
                if ( p -> right != NULL) {
                    q -> next = p -> right;
                    q = q -> next;
                }
                p = p ->next;
            }
            q -> next = NULL;
            curHead = nextHead;
        }
    }
    
    //Should use a more meaningful name
    TreeLinkNode * findNextHead(TreeLinkNode * cur, TreeLinkNode * & nextHead) {
        while ( cur != NULL) {
            if ( cur -> left) {
                nextHead = cur -> left;
                return cur;
            }
            if ( cur -> right) {
                nextHead = cur -> right;
                return cur;
            }
            cur = cur -> next;
        }
        return NULL;
    }
};