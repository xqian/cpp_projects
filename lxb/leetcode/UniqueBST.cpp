http://oj.leetcode.com/problems/unique-binary-search-trees/

/*Question:
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

Solution: 1. DFS.
	  1. DP.

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


Method2: DP  
class Solution {
public:
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       
       // DP[i]: the unique BST numbers for 1..i;
       // DP[0] = 1;
       // DP[i] += DP[j] * DP[i-j-1] : j=[0..i-1]
       // return DP[n]

       vector<int> DP(n+1,0); 
       DP[0] = 1;

       for (int i=1; i<=n; ++i)
       {
            for (int j=0; j<i; ++j)
            {
                DP[i] += DP[j]*DP[i-j-1];
            }
       }
       
       return DP[n];
    }
};
