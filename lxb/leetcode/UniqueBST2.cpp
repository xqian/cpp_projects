http://oj.leetcode.com/problems/unique-binary-search-trees-ii/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

Solution: DFS.

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return generateTreesHelper(1,n);
    }
    
    vector<TreeNode *> generateTreesHelper(int start, int end){
        vector<TreeNode *> result;
        if (start > end) {
            result.push_back(NULL);
            return result;
        }
        
        for (int i=start; i<= end; i++){
            vector<TreeNode *> leftTrees  = generateTreesHelper(start,i-1);
            vector<TreeNode *> rightTrees = generateTreesHelper(i+1,end);
            
            for (int j=0;j<leftTrees.size();j++)
            for (int k=0;k<rightTrees.size();k++){
                TreeNode *root = new TreeNode(i);
                root->left = leftTrees[j];
                root->right = rightTrees[k];
                result.push_back(root);
            }
        }
        
        return result;
    }
};
