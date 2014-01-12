/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
    For example, given array S = {-1 2 1 -4}, and target = 1.
    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

// Focus:  1. Arrays.sort(arr);
	   2. Integer.MAX_VALUE
	   3. Math.abs(12)
	   4. record the min value

public class Solution {
    public int threeSumClosest(int[] num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        Arrays.sort(num);
        int res = 0;
        int minV = Integer.MAX_VALUE;
        
        for (int i=0; i<num.length - 2; ++i)
        {
            int j = i+1;
            int k = num.length - 1;

            while (j<k){
                if (num[i] + num[j] + num[k] == target) return target;
                if (num[i] + num[j] + num[k] < target){
                    if (Math.abs(num[j] + num[k] + num[i] - target) < minV){
                        minV = Math.abs(num[i] + num[j] + num[k] - target);
                        res = num[i] + num[j] + num[k];
                    }
                    j++;
                }else{
                    if (Math.abs(num[j] + num[k] + num[i] - target) < minV){
                        minV = Math.abs(num[i] + num[j] + num[k] - target);
                        res = num[i] + num[j] + num[k];
                    }
                    k--;
                }
            }
        }
        
        return res;
    }
}
