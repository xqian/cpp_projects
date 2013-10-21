http://oj.leetcode.com/submissions/detail/707468/

class Solution {
public:

    void swap( int &a, int &b){
        int c = a;
        a = b;
        b = c;
    }
    
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int size = num.size();
        
        if (size ==0 || size == 1) return;
        
        // from end to begin, find first reverse ordered number
        int e = size - 1;
        for (; e>0; e--){
            if ( num[e] > num[e-1] ) break;
        }
        
        if (e == 0) {
            sort(num.begin(), num.end());
            return ;
        }
        
        // This is the location to exchange;
        e--;
        
        // from end to begin again, find first value who is greater than step 1: e
        int e2 = size - 1;
        for (; e2>0; e2--){
            if ( num[e2] > num[e] ) break;
        }
        
        // swap step1 and step2
        swap(num[e2],num[e]);
        
        // reverse the whole part
        e++;
        int n = size - 1;
        while (e<=n) swap(num[e++],num[n--]);
        
        // return it
        return; 
    }
};
