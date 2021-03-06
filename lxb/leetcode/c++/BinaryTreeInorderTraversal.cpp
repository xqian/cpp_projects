http://oj.leetcode.com/submissions/detail/724934/

/*
iven a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
*/

Solution 1: 1) iterative  + stack
	    2) Morris inorder travel.

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
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        stack<TreeNode*> S;

        TreeNode *curr = root;
        
        while(1){
            if (curr)  {
                S.push(curr);
                curr=curr->left;
                continue;
            }
            
            //end
            if (S.empty()) break;
            
            //left most node,visit it.
            curr = S.top();
            S.pop();
            result.push_back(curr->val);
            
            // move to right child
            if (curr->right) curr = curr->right;
            else curr = NULL;
        }
        
        return result;
    }
};


Method 2: Morris inorder travel

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
    vector<int> inorderTraversal(TreeNode *root) {
        
       //Morris InOrder travel , space O(1), but it modified the node.
       vector<int> res;
       TreeNode *curr = root;
       
       while(curr){
           if (curr->left){
                auto *prev = curr->left;
                
                //find previous node 
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                
                if (prev->right){
                    //second time
                    prev->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }else{
                    //first time
                    prev->right = curr;
                    curr = curr->left;
                }
           }else{
               res.push_back(curr->val);
               curr=curr->right;
           }
       }
       
    return res;
    }
};
