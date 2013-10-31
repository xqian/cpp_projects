http://oj.leetcode.com/submissions/detail/1006731/

class Solution {
public:
    string intToRoman(int num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int digital[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string result;
        int index = 0;
        while(num>0){
            int times = num/digital[index];
            for (int j=0; j<times; j++) result += symbol[index];
            num -= digital[index]*times;
            index++;
        }
        
        return result;
    }
};
