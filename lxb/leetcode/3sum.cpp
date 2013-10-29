http://oj.leetcode.com/problems/3sum/

//version 2: This one passed!!
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        sort(num.begin(), num.end());
        vector <vector<int> > result;
        
        if (num.size() < 3) return result;
        
        vector<int> triple(3);
        
        for (int i=0; i<num.size()-2; i++){
            //skip duplicate
            if (i > 0 && num[i] == num[i-1]) continue;
            int j = i+1;
            int k = num.size()-1;
            
            int two_sum = 0 - num[i];
            while(j<k){
                if (num[j] + num[k] > two_sum ) k--;
                else if (num[j] + num[k] < two_sum) j++;
                else {
                    triple[0] = num[i];
                    triple[1] = num[j];
                    triple[2] = num[k];
                    result.push_back(triple);
                    j++;
                    k--;
                    
                    while (j < k && num[j] == num[j-1]) j++;
                    while (k > j && num[k] == num[k+1]) k--;
                }
            }
        }
        
        return result;
    }
};
