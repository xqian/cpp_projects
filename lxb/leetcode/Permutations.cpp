http://oj.leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int>> result;
        int index = 0;
        permuteHelper(result,num,0);
        
        return result;
    }
    
    void swap(int &a, int &b){
        int c = a;
        a = b;
        b = c;
    }
    
    void permuteHelper(vector<vector<int>> &result, vector<int> &num, int index){
        //base
        if (index == num.size()-1){
            result.push_back(num);
            return;
        }
        
        //permute
        for (int i=index; i<num.size(); i++){
            swap(num[i],num[index]);
            permuteHelper(result,num,index+1);
            swap(num[i],num[index]);
        }
    }
    
};
