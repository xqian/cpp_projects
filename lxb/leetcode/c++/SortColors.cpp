http://oj.leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int index0 = -1;
        int j=0;
        int index2 = n;
        
        while (j<index2){
            switch (A[j]){
                case 0:
                    swap(A[++index0],A[j++]);
                    break;
                case 1:
                    j++;
                    break;
                case 2:
                    swap(A[j],A[--index2]);
                    break;
            }
        }
        
        return;
    }
    
    void swap(int &a, int &b)
    {
        int c = a;
        a = b;
        b = c;
    }
};
