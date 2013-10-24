http://oj.leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        return numTreesHelper(1,n);
    }
    
    int numTreesHelper(int start,int end){
        if (start >= end) return 1;
        
        int num = 0;
        for (int i= start; i<=end; i++){
            num += numTreesHelper(start, i-1) * numTreesHelper(i+1,end);
        }
        
        return num;
    }
};
