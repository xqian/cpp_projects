http://oj.leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        assert(n>0);
        
        int sum = A[0];
        int maxSum = A[0];
        
        for (int i=1;i<n;i++){
            if (sum < 0) sum = 0;
            sum += A[i];
            
            if (maxSum < sum) {
                maxSum = sum;
            }
        }
        
        return maxSum;
    }
};
