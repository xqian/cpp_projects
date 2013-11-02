http://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/

/* Question:
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

class Solution {
private:
    string map[10] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void helper(vector<string> &result, const string &digits, string oneResult, int index)
    {
        if (index == digits.size()){
            result.push_back(oneResult);
            return;
        }   
        
        for (int i=0; i < map[digits[index]-'0'].size();i++){
            helper(result,digits, oneResult+map[digits[index] - '0'][i], index+1);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        
        if (digits.empty()) {
            vector<string> resultEmpty(1,"");
            return resultEmpty;
        }
        
        string oneResult;
        helper(result,digits,oneResult,0);
        return result;
    }
};
