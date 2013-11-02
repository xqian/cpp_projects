http://oj.leetcode.com/problems/maximum-subarray/

/*Question
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Discuss


*/

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
