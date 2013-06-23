//This is a very cumbersome problem
//Need to consider INT_MIN, which is very tricky
//next time just cast to long long to avoid those code
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (dividend == 0 || divisor == 0) return 0;
        if (dividend == divisor) return 1;
        if (divisor == INT_MIN) return 0;
        bool isNeg = false;
        unsigned int d1;
        unsigned int d2; 
        if ( dividend < 0) {
            isNeg = !isNeg;
            if( dividend == INT_MIN) {
                d1 = (unsigned int) dividend;
            }
            else {
                d1 = (unsigned int) (0 - dividend);
            } 
        }
        else {
            d1 = dividend;
        }
        if ( divisor < 0) {
            isNeg = !isNeg;
            d2 = (unsigned int) (0 - divisor);
        }
        else {
            d2 = divisor;
        }
        if ( d1 < d2) return 0;
        int numShft = 0;  
        unsigned int a = d1;   //BUG: if left shift divisor, may cause overflow and infinite loop   
        while(a >= d2) {
            a >>=1;
            numShft++;
        }        
        numShft--;
        d2 <<= numShft;
        int res = 0;
        for(int i=0; i <= numShft; ++i) {
            res <<=1;
            if ( d1 >= d2) {
                d1 -= d2;
                res +=1;
            }
            d2 >>=1;
        }
        if ( isNeg) return 0-res;
        else return res;
    }
};