http://oj.leetcode.com/problems/3sum-closest/
/*
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Discuss


 */

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        sort(num.begin(), num.end());
        int minV = INT_MAX;
        int result;
        
        for (int i=0; i<num.size(); i++)
        {
            int j = i+1;
            int k = num.size() - 1;
            
            while (j < k)
            {
                if (num[j] + num[k] == target - num[i]) return target;
                if (num[j] + num[k] < target - num[i]) {
                    if (abs(target - num[i] - num[j] - num[k]) < minV ){
                        minV = abs(target - num[i] - num[j] - num[k]);
                        result = num[i] +num[j] +num[k];
                    }
                    j++;
                }else{
                    if (abs(target - num[i] - num[j] - num[k]) < minV ){
                        minV = abs(target - num[i] - num[j] - num[k]);
                        result = num[i] +num[j] +num[k];
                    }
                    k--;
                }
            }
        }
        
        return result;
    }
};
