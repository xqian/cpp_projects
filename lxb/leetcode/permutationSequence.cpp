http://oj.leetcode.com/problems/permutation-sequence/

/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
 */

Solution: compute each position using candor encoding method.
	2) assume the result is a1 a2 a3..an, if we remove a1, those  (n-1)!,  so a1 = k/(n-1)!
	   then if we remove a2, total a3..an (n-2)!, k' = k%(n-1)!, a2 = k'/(n-2)!
	3) remember to remove the element if chosen.
	4) Refer Leetcode 题解 page19.

class Solution {
public:
    string getPermutation(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
    
        // base string '1234..'
        string S;
        for (int i=1; i<=n; i++) S += i+'0';
        
        //factor
        int total = 1;
        for (int i=1; i<n; ++i) total *= i;
        
        string res;
        k--; //candor encoding start from 0;
        
        //candor encoding to compute each bit.
        for (int i=n-1; i>0; --i)
        {
            res.push_back(S[k/total]);
            S.erase(S.begin()+k/total); //it has been used, so remove it.
            k = k % total;
            total = total / i;  //factor(i-1)
        }
        
        //last one
        res.push_back(S[0]);
        
        return res;
    }
};
