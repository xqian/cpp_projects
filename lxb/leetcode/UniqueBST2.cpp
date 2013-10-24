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
        
         if (start == end)  {
             result.push_back(new TreeNode(start));
             return result;
         }
        
        for (int i=start; i<= end; i++){
            vector<TreeNode *> left  = generateTreesHelper(start,i-1);
            vector<TreeNode *> right = generateTreesHelper(i+1,end);
            
            //merge.. ??
            for (int j=0;j<left.size();j++)
            for (int k=0;k<right.size();k++){
                TreeNode *root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                result.push_back(root);
            }
        }
        
        return result;
    }
    
    
};
