http://oj.leetcode.com/problems/3sum-closest/

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
