http://oj.leetcode.com/problems/sqrtx/
/*
 Question:
Implement int sqrt(int x).

Compute and return the square root of x
*/

class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (x < 2) return x;
        
        int low = 0;
        int high = x;
        int mid;
        while(low<high){
            //Pay attention to Integer overflow
            mid = low + (high-low-1)/2 + 1;
            
            int div = x/mid;
            if (mid == div) return mid;
            else if (mid > div ) high = mid - 1;
            else low = mid;
            }
        
        return low;
    }
};

Variation: double sqrt(double r)
double sqrt(double r){
	//special case
	assert(r>=0);
	if (r == 1) return 1.0;

	//L: Left, or lower  R:right or higher.
	double L = r>1?1:r;
	double R = r>1?r:1;

	double eplison=0.00001;

	while (eplison<R-L){
		double mid = L + (R-L)/2;
		double m = mid * mid;
		if (m > r){
			R = m;
		}else{
			L = m;
		}
	}

	return L;
}

