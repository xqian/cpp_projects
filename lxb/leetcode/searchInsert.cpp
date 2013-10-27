http://oj.leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int L = 0;
        int R = n-1;
        
        while (L<=R){
            int mid = L + (R-L+1)/2;
            if (A[mid] == target) return mid;
            else if (A[mid] > target){
                R = mid - 1;
            }else{
                L = mid + 1;
            }
        }
        
        // not find
        return L;
    }
};
