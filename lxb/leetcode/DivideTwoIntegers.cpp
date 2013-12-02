http://oj.leetcode.com/problems/divide-two-integers/

/*
Divide two integers without using multiplication, division and mod operator.
*/
solution: 1. overflow, long long static conversion.
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        assert(divisor != 0);
        
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;

        //sign
        bool negative = false;
        if ((dividend > 0 && divisor < 0) || (dividend <0 && divisor >0)){
            negative = true;
        }
        
        long long dividendll = abs((long long)dividend);
        //long long dividendll = abs(static_cast<long long>(dividend));
        long long divisorll = abs((long long)divisor);
        
        //when divisor is -1 and dividend is INT_MAX, return will be overflow.
        int result = 0;
        
        while(dividendll >= divisorll)
        {
	    // naming, abbrev.
            long long div = divisorll;
            long long count = 1;

	    // tip: check condition.
            while ((div<<1) <= dividendll)
            {
                div <<= 1;
                count <<= 1;
            }
            
            dividendll -= div;
            result +=count;
        }
        
        return negative?-result:result;
    }
};

/* Note: This method didn't work !
 * If we use int, it will report time limit exceeded and there is some integer overflow 
   eg: Submission Result: Time Limit Exceeded
Last executed input:	2147483647, 2
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        assert(divisor != 0);
        
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;

        //sign
        bool negative = false;
        if ((dividend > 0 && divisor < 0) || (dividend <0 && divisor >0)){
            negative = true;
        }
        
        int dividendll = abs(dividend);
        int divisorll = abs(divisor);
        
        //when divisor is -1 and dividend is INT_MAX, return will be overflow.
        int result = 0;
        
        while(dividendll >= divisorll)
        {
            int div = divisorll;
            int count = 1;
            while ((div<<1) <= dividendll)
            {
                div <<= 1;
                count <<= 1;
            }
            
            dividendll -= div;
            result +=count;
        }
        
        return negative?-result:result;
    }
};
