// when L<R : mid = L + (R-L-1)/2 +1
// when check L<=R : mid = L+(R-L)+1)/2;

class Solution {
public:
    bool search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int L = 0;
        int R = n-1;
        
        while(L <= R)
        {
            int mid = L + (R-L+1)/2;  //Ceiling
            if (A[mid] == target) return true;
            
            if (A[L] < A[mid]){
                //L .. mid is normal sorted
                if (A[L] <= target && target < A[mid]){
                    R = mid - 1;
                }else{
                    L = mid + 1;
                }
                
            }else if (A[L] > A[mid]){
                //mid .. R is normal sorted
                if (A[mid] < target && target <= A[R]){
                    L = mid + 1;
                }else{
                    R = mid - 1;
                }
            }else{
                L++;
            }
        }
        
        return false;
    }
};

class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        // lower boundary.
        assert(x>=0);
        
        if (x < 2) return x;
        
        int L = 0;
        int R = x;
        
        while (L < R)
        {
            int mid = L + (R-L-1)/2 + 1;
            int div = x/mid;
            
            if (mid == div) return mid;
            if (mid < div) {
                L = mid;
            }else{
                R = mid - 1;
            }
        }
        
        return L;
    }
};
