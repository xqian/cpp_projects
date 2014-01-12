/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

// Focus: 1. compare with index or value.  

public class Solution {
    public int trap(int[] A) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (A.length <=1 ) return 0;
        
        // 1. Find the max value
        int maxIndex=0;
        for (int i=0; i<A.length; ++i){
            if (A[i] > A[maxIndex]) maxIndex =i;
        }
        
        // left side.
        int maxSoFar = A[0];
        int sum = 0;
        for (int left=1; left < maxIndex; left++){
            if (maxSoFar < A[left]) maxSoFar = A[left];
            sum += (maxSoFar - A[left])*1;
        }
        
        //right side.
        maxSoFar = A[A.length-1];
        for (int right = A.length-1; right >maxIndex; --right){
            if (maxSoFar < A[right]) maxSoFar = A[right];
            sum += (maxSoFar - A[right])* 1;
        }
        
        return sum;
    }
}
