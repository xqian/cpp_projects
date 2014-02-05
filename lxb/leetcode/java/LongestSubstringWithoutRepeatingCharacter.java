/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
Focus:  1. boolean hash array and its default value is false
	2. two pointer, move pointer and maintain the boolean hash array.

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() <= 1) return s.length();
        
        boolean[] appear = new boolean[256];
        int begin = 0;
        int end = 0;
        int max = 0;
        
        while (end < s.length()) {
            if (appear[s.charAt(end)] == true) {
                if (max < end - begin) {
                    max = end - begin;
                }
                
                //move begin
                appear[s.charAt(begin)] = false;
                begin++;
                continue;
            } else {
                appear[s.charAt(end)] = true;
            }
            end++;
        }
        
        //last compare
        if (max < end - begin) {
            max = end - begin;
        }
        
        return max;
    }
}
