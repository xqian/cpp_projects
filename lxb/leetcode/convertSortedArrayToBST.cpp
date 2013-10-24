http://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (num.size() == 0) return NULL;
        
        return sortedArrayToBSTHelper(num, 0,num.size()-1);
    }
    
    TreeNode *sortedArrayToBSTHelper(vector<int> &num, int low, int high){
        if (low==high) { return (new TreeNode(num[low]));};
        if (low > high) return NULL;
        
        int mid = low + (high - low + 1)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = sortedArrayToBSTHelper(num, low, mid-1);
        root->right = sortedArrayToBSTHelper(num, mid+1, high);
        
        return root;
    }
};
