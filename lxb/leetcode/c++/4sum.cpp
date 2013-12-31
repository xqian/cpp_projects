http://oj.leetcode.com/submissions/detail/1006075/

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > result;
        int N = num.size();
        if (N<4) return result;
        
        sort(num.begin(), num.end());
        
        
        for (int i=0; i<N-3; i++)
        {
            //handle duplicate
            if (i > 0 && num[i] == num[i-1]) continue;
        
            for (int j=N-1; j>i; j--)
            {
                if (j<N-1 && num[j] == num[j+1]) continue;
                
                int expectedSum = target - num[i] - num[j];
                // now, it becomes 2Sum problem.
                int begin = i+1;
                int end = j-1;
                while(begin < end){
                    //handle duplicate
                    if (begin-1 > i && num[begin] == num[begin-1]) {
                        begin++;
                        continue;
                    }
                    
                    if (end+1 < j && num[end] == num[end+1]){
                        end--;
                        continue;
                    }
                    
                    if (num[begin] + num[end] == expectedSum){
                        //one solution.
                        vector<int> oneSolution;
                        oneSolution.push_back(num[i]);
                        oneSolution.push_back(num[begin]);
                        oneSolution.push_back(num[end]);
                        oneSolution.push_back(num[j]);
                        
                        result.push_back(oneSolution);
                        
                        begin++;
                        end--;
                    } else if (num[begin] + num[end] < expectedSum) begin++;
                    else end--;
                }
                
            }
        }
        
        return result;
    }
};
