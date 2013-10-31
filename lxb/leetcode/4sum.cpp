http://oj.leetcode.com/submissions/detail/1006075/

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
