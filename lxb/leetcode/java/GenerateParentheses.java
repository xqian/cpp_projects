/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"
*/
//Focus: 1. String init, similar as object. String str = new String() 
	 2. depth search.
	 3. ArrayList pass as reference/object and can carry back the value.

public class Solution {
    public ArrayList<String> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ArrayList<String> res = new ArrayList<String>();
        String oneRes=new String();
        
        dfs(n,n,res,oneRes);
        return res;
    }
    
    private void dfs(int numLeft, int numRight, ArrayList<String> res, String oneRes){
        //base
        if (numLeft == 0 && numRight == 0){
            res.add(oneRes);
            return;
        }
        
        //extension
        if (numLeft>0) dfs(numLeft-1, numRight, res, oneRes+'(');
        if (numRight>0 && numRight>numLeft) dfs(numLeft, numRight-1, res, oneRes + ')');
    }
}
