http://oj.leetcode.com/problems/combinations/

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        vector<int> oneSolution;
        
        combineHelper(k, n, oneSolution, result,1);
        return result;
    }
    
    void combineHelper(int k, int n, vector<int> s, vector<vector<int> > &r,int index){
        //base
        if (k==0){
            r.push_back(s);
            return;
        }
        
        if (index <= n)
        {
            //choose current one:
            s.push_back(index);
            combineHelper(k-1, n, s, r, index+1);
            
            //or not choose.
            s.pop_back();
            combineHelper(k, n, s, r, index+1);
        }
    }
};
