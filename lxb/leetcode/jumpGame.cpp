http://oj.leetcode.com/problems/jump-game/

/*
Question:
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

        //greedy method.
        int nextStep = 0;
        int index = 0;
        while(true){
            nextStep += A[index];
            if (index == nextStep) break;
            
            index = nextStep;
            
            if (index >=n || nextStep >= n-1) break;
        }
        
        return nextStep >=n-1 ? true:false;
    }
};
