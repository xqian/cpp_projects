/*
Implement int sqrt(int x).
Compute and return the square root of x.
*/
Focus:  1. special case
	2. L = mid
public class Solution {
    public int sqrt(int x) {
        if (x == 0) return 0;
        int L = 1;
        int R = x;
        int mid = L;

        while (L < R) {
            mid = L + (R - L + 1) / 2;
            int div = x / mid;
            if (div < mid) {
                R = mid - 1;
            } else if (div > mid) {
                L = mid;
            } else {
              return mid;  
            }
        }
        
        return L;
    }
}
