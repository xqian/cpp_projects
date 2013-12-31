http://oj.leetcode.com/problems/remove-element/
/*Question
  Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i = -1;
        int j = n-1;
        
        while(i<j){
            if (A[i+1] == elem){
                //swap(A[i+1],A[j--]);
                int tmp = A[i+1];
                A[i+1] = A[j];
                A[j--] = tmp;
            }else{
                i++;
            }
        }
        
        return i+1;
    }
};
