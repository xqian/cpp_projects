http://oj.leetcode.com/problems/multiply-strings/

/* Question:
Given two numbers represented as strings, return multiplication of the numbers as a string.
Note: The numbers can be arbitrarily large and are non-negative.
*/

Solution: simply multiply, start from less-important bit.
class Solution {
public:
    string multiply(string num1, string num2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (num1 == "0" || num2 == "0") return "0";
        
        int N1 = num1.size();
        int N2 = num2.size();
        
        string res(N1+N2,'0');
        
        for (int i=N1-1; i>=0; i--)
        {
            int carrier = 0;
            for (int j=N2-1; j>=0; j--)
            {
                int sum = carrier + (num1[i] - '0')*(num2[j] - '0') + (res[i+j+1] - '0');
                carrier = sum / 10;
                res[i+j+1] = sum % 10 + '0';
            }
            
            res[i] += carrier;
        }
        
        //remove '0' in the head.
        int count = 0; 
        while (count < res.size() && res[count] == '0') count++;
        
        return res.substr(count);
    }
};
