http://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int count = 0;
        int j = -1;
        for (int i=0; i<n ;i++)
        {
            if (!hasAppeared(A,j,A[i],n)){
                A[++j] = A[i];
                count++;
            }
        }
        
        return count;
    }
    
    bool hasAppeared(const int A[], int j, int key, int n)
    {
        //binary search A[i] in range A[0..j]
        if (j == -1) return false;
        
        int low = 0;
        int high = j;
        while (low <= high){
            int mid = low + (high-low+1)/2;
            if (A[mid] == key) return true;
            if (A[mid] < key) low = mid+1;
            else high = mid - 1;
        }
        
        return false;
    }
};
