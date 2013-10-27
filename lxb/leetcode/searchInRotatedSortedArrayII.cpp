http://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int L = 0;
        int R = n-1;
        
        while(L<=R){
            int mid = L + (R-L+1)/2;
            if (A[mid] == target) return true;
            
            if (A[L] < A[mid]){
                //left side is restrictly sorted
                if (A[mid] > target && A[L] <= target) R = mid - 1;
                else    L = mid + 1;
            }else if (A[L] > A[mid]){
                //right side is sorted
                if (A[mid] < target && A[R] >= target) L = mid + 1;
                else R = mid - 1;
            }else{
                //duplicate. A[L..mid] is same value.
                L++;
            }
        }
        
        return false;
    }
};
