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

// Method 2: DP. one of error.
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> DP[n+1];
        DP[0] = vector<TreeNode *>(1,(TreeNode *)NULL);
        
        for (int i=1; i<=n; ++i)
        for (int j=1; j<=i; ++j)
        {
            for (int k=0; k<DP[j-1].size(); ++k)
            for (int m=0; m<DP[i-j].size(); ++m)
            {
                TreeNode *root = new TreeNode(j);
                copyNode(DP[j-1][k], root->left, 0);
                copyNode(DP[i-j][m], root->right, j);
                DP[i].push_back(root);
            }
        }
        
        return DP[n];
    }
    
    void copyNode(TreeNode *ori, TreeNode *&copy, int shift)
    {
        if (!ori) return;
        copy = new TreeNode(ori->val+shift);
        copyNode(ori->left, copy->left, shift);
        copyNode(ori->right, copy->right, shift);
    }
};
