http://oj.leetcode.com/problems/jump-game-ii/

/*Question
  Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

*/

More simplier one:

class Solution {
public:
    int jump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (n<2) return 0;
        
        int jumps = 0;
        int start = 0;
        while ( start < n ) 
        {
            jumps++;
            if (start + A[start] >= n-1) return jumps;
            
            int mx = start;
            for (int i=start + 1; i<=start+A[start]; ++i){
                if (i + A[i] >= mx + A[mx] ){
                    mx = i;   
                }
            }
            
            start = mx;
        }
    }
};


Method 1: Greedy

class Solution {
public:
    int jump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (n<2) return 0;
        
        //greedy
        int jumps = 0;
        int maxLevel = 0;
        
        int i = 0;
        while ( i < n ) 
        {
            jumps++;
            int oldMaxLevel = maxLevel;
            
            //one jump, how far it can get.
            do {
                if (i + A[i] > maxLevel )
                {
                    maxLevel = i + A[i];   
                }
                
                if (maxLevel >= n-1) return jumps;
                
                i++;
            }while( i <= oldMaxLevel );
        }
    }
};


Method(2): dp
//Note: This solution exceed max time. Need O(n) solution.
class Solution {
public:
    int jump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        if (n<2) return 0;
        
        //S[i] means the minum steps to jump to reach index i. [0..i]
        vector<int> S(n,INT_MAX);
        S[0] = 0;
        
        //O(n2)
        for (int i=1; i<n; i++){
            for (int j=0; j<i; j++){
                if ( j + A[j] >= i){
                    if (S[j] + 1 < S[i]) S[i] = S[j] + 1;
                }
            }
        }
        
        return S[n-1];
    }
};
