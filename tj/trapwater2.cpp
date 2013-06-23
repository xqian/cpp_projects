class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( n == 0) return 0;
        int res = 0;
        int left = 0;
        int right = n-1;
        
        while( left < right) {
            if ( A[left] < A[right]) {
                int h = A[left];
                left++;
                while( left < right && A[left] <= h) {
                    res += (h - A[left]);
                    left++;
                }
            }
            else {
                int h = A[right];
                right--;
                while( left < right && A[right] <= h) {
                    res += (h-A[right]);
                    right--;
                } 
            }
        }
        return res;
    }
};
