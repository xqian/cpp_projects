http://oj.leetcode.com/problems/3sum/

//Note: Memory limit exceeded

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        sort(num.begin(), num.end());
        vector <vector<int> > result;
        vector<int> triple(3);
        
        for (int i=0; i<num.size(); i++){
            //skip duplicate
            if (i > 0 && num[i] == num[i-1]) continue;
            int j = i+1;
            int k = num.size()-1;
            
            int two_sum = 0 - num[i];
            while(j<k){
                if (j > 0 && num[j] == num[j-1]) {j++; continue;}
                if (k < num.size()-1 && num[k] == num[k+1]) {k--; continue;}
                
                if (num[j] + num[k] > two_sum ) k--;
                else if (num[j] + num[k] < two_sum) j++;
                else {
                    triple.clear();
                    triple[0] = num[i];
                    triple[1] = num[j];
                    triple[2] = num[k];
                    result.push_back(triple);
                }
            }
        }
        
        return result;
    }
};
