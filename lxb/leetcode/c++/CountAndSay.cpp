http://oj.leetcode.com/problems/count-and-say/

/*
Question:
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
class Solution {
public:
    string countAndSay(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        string str = "1";
        for (int i=1; i<n; i++){
            countAndSayHelper(str);
        }
        
        return str;
    }
    
    void countAndSayHelper(string &str){
        if (str.size()==0) return;
        string result;
        char lastChar = str[0];
        int count = 0;
        for (int i=0; i<str.size(); i++){
            if (str[i] == lastChar){
                count++;
                continue;
            }else{
                result += to_string(count);
                result += lastChar;
                
                lastChar  = str[i];
                count = 1;
            }
        }
        
        //last one
        result += to_string(count) + lastChar;
        
        str = result;
        return;
    }
};
