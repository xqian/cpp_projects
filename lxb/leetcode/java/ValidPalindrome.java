/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

Focus: 1. Character.toUpperCase(c) , write your own isAlphabet function is easier
public class Solution {
    public boolean isPalindrome(String s) {
        //empty string
        if (s.length() == 0) return true;
       
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            //skip space
            if (isAlphabet(s.charAt(left)) == false) {
                left++;
            }else if (isAlphabet(s.charAt(right)) == false) {
                right--;
            }else if (Character.toUpperCase(s.charAt(left)) != Character.toUpperCase(s.charAt(right))) {
                return false;
            }else {
                left++;
                right--;
            } 
        }
        return true;
    }
    
    private boolean isAlphabet(char c) {
		return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z' ) || (c >= '0' && c <= '9');
	}
}
