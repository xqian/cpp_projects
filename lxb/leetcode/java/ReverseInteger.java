/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

//Focus: 1. while x!=0, vs while (x) in c++.
	 2. boolean, vs bool in c++.
	 3. Math.abs(x)

public class Solution {
    public int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (x==0) return 0;
        
        boolean sign = false;
        if (x < 0){
            x = Math.abs(x);
            sign = true;
        }
        
        int res = 0;
        while (x!=0){
            res = res*10 + x%10;
            x=x/10;
        }
        
        if (sign) res = -res;
        
        return res;
    }
}
