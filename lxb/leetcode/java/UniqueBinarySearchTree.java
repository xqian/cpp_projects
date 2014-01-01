/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
Discuss
*/
public class Solution {
    public int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n<=1) return 1;
        
        int res = 0;
        for (int i=1; i<=n;++i ){
            res += numTrees(i-1) * numTrees(n-i);
        }
        
        return res;
    }

}
