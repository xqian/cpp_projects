http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
/*
Question:
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (n<3) return n;
        
        int curr = 1;
        for (int j = 2; j<n; j++){
            if (!(A[j] == A[curr] && A[j] == A[curr-1]))
            { 
                A[++curr] = A[j];
            }
        }
        
        return curr+1;
    }
};
