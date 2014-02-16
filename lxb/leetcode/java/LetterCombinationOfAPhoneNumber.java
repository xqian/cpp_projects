http://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Discuss


*/

public class Solution {
    public ArrayList<String> letterCombinations(String digits) {
        char[][] map = { {'\0'}, {'\0'}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'},
                        {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'} };
        //Tip: Using StringBuilder for temporary string + append method.
        StringBuilder sb = new StringBuilder();
        ArrayList<String> res = new ArrayList<String>();
        dfs(digits, 0, sb, res, map);
        return res;
    }
    
    private void dfs(String digits, int index, StringBuilder sb, ArrayList<String> res, char[][] map) {
        if (index >= digits.length()) {
            res.add(sb.toString());
        } else {
            int m = digits.charAt(index) - '0';
            int len = map[m].length;
            for (int i = 0; i < len; ++i) {
                sb.append(map[m][i]);
                dfs(digits, index + 1, sb, res, map);
                //Tip: how to delete last element of StringBuilder
                sb.deleteCharAt(sb.length() - 1);
            }
        }
    }
}
