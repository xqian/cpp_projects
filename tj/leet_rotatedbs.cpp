class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( n == 0) return -1;

        int left = 0;
        int right = n-1;
        
        while( left < right -1) {
            int mid = left + (right - left)/2;
            if ( A[mid] < A[right]) {
                if ( A[mid] <= target && target <= A[right]) {
                    return bsearch(A, mid, right, target);
                }
                else {
                    right = mid-1;
                }
            }
            else { //mid> right
                if ( A[left] <= target && target <= A[mid]) {
                    return bsearch(A, left, mid, target);
                }
                else {
                    left = mid+1;
                }
            }
        }
        return ssearch(A, left, right, target);

    }
    
    int ssearch(int A[], int left, int right, int target) {
        while( left <= right) {
            if ( A[left] == target) return left;
            left++;
        }
        return -1;
    }
    
    int bsearch(int A[], int left, int right, int target) {
        while (left < right -1) {
            int mid = left + (right-left)/2;
            if ( A[mid] < target) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        return ssearch(A, left, right, target);
    }
    
};