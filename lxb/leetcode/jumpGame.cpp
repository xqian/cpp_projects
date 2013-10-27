http://oj.leetcode.com/problems/jump-game/

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
