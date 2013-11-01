http://oj.leetcode.com/problems/next-permutation/

Question:
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

/*
Here are some examples of the steps on (1, 2, 3, 4) that should clarify step 2a, 2b and 3:

(1, 2, 3, 4) >> (1, 2, 3), (4) >> (1, 2, 4), (3) >> (1, 2, 4), (3) >> (1, 2, 4, 3)
(1, 2, 4, 3) >> (1, 2), (4, 3) >> (1, 3), (4, 2) >> (1, 3), (2, 4) >> (1, 3, 2, 4)
(1, 3, 2, 4) >> (1, 3, 2), (4) >> (1, 3, 4), (2) >> (1, 3, 4), (2) >> (1, 3, 4, 2)
(1, 3, 4, 2) >> (1, 3), (4, 2) >> (1, 4), (3, 2) >> (1, 4), (2, 3) >> (1, 4, 2, 3)
Here are some examples on the sequence (1, 2, 2, 3):

(1, 2, 2, 3) >> (1, 2, 2), (3) >> (1, 2, 3), (2) >> (1, 2, 3), (2) >> (1, 2, 3, 2)
(1, 2, 3, 2) >> (1, 2), (3, 2) >> (1, 3), (2, 2) >> (1, 3), (2, 2) >> (1, 3, 2, 2)
(1, 3, 2, 2) >> (1), (3, 2, 2) >> (2), (3, 2, 1) >> (2), (1, 2, 3) >> (2, 1, 2, 3)

*/

class Solution {
public:

    void swap( int &a, int &b){
        int c = a;
        a = b;
        b = c;
    }
    
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int size = num.size();
        
        if (size ==0 || size == 1) return;
        
        // from end to begin, find first reverse ordered number
        int e = size - 1;
        for (; e>0; e--){
            if ( num[e] > num[e-1] ) break;
        }
        
        if (e == 0) {
            sort(num.begin(), num.end());
            return ;
        }
        
        // This is the location to exchange;
        e--;
        
        // from end to begin again, find first value who is greater than step 1: e
        int e2 = size - 1;
        for (; e2>0; e2--){
            if ( num[e2] > num[e] ) break;
        }
        
        // swap step1 and step2
        swap(num[e2],num[e]);
        
        // reverse the whole part
        e++;
        int n = size - 1;
        while (e<=n) swap(num[e++],num[n--]);
        
        // return it
        return; 
    }
};
