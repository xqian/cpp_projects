http://oj.leetcode.com/submissions/detail/678794/

class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int sign = 1;
        if ( n < 0 ) {
            sign = -1;
            n *= sign;
        }
        
        double r = powHelper(x,n);
        return sign>0 ? r: 1/r;
    }
    
    double powHelper(double x, int n){
        if (n== 0) return 1;
        if (n== 1) return x;
       
        double r = pow(x,n/2);
        r = r*r;
        if (n&1) r *= x;
        return r;
    }
};
