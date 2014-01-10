/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

Discuss
*/
public class Solution {
    public int removeDuplicates(int[] A) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (A.length <= 2) return A.length;
        
        int i=0; 
        int j=1;
        int count = 1;
        for (;j<A.length; ++j){
            if (A[i]==A[j]){
                count++;
                if (count <=2){
                    A[++i] = A[j];
                }
            }else{
                count = 1;
                A[++i] = A[j];
            }
        }
        
        return i+1;
    }
}

public class Solution {
    public int removeDuplicates(int[] A) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (A.length <= 2) return A.length;

        int j=2;
        int curr = 1;
        for (;j<A.length; ++j){
            if !(A[curr]==A[j] && A[j] == A[curr-1]){
                A[++curr] = A[j];
            }
        }
        
        return curr+1;
    }
}
