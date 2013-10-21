http://oj.leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (x == 0) return 0;
        
        bool negative = x > 0? false : true;
        x = abs(x);
        
        int reverse = 0;
        while (x){
            reverse = reverse*10 + x%10;
            x = x/10;
        }
        
        //overflow handle
        if (reverse < 0)
        {
            cout << "overflow happened" << endl;
        }
        
        if (negative){
            reverse = reverse * (-1);
        }
        
        return reverse;
    }
};
