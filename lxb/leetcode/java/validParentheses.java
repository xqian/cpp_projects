/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
//Focus: 1. Stack<Character>  ,similar Integer  . stack.push(c), stack.pop(), stack.empty()
	 2. String operation. str.charAt(i), str.length()
	 3. Boundary check for stack when stack.pop(), check stack.empty()

public class Solution {
    public boolean isValid(String s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        Stack<Character> stack = new Stack<Character>();
        for(int i=0; i<s.length(); ++i){
            if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) =='['){
                stack.push(s.charAt(i));
            }else{
                if (stack.empty() == true) return false;
                if (s.charAt(i) == ')' && stack.pop() !='(') return false;
                if (s.charAt(i) == '}' && stack.pop() !='{') return false;
                if (s.charAt(i) == ']' && stack.pop() !='[') return false;
            }
        }
        
        if (stack.empty()) return true;
        
        return false;
    }
}
