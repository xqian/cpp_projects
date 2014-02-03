/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Discuss
*/

Focus: 1. Java Map usage:  Map is an interface. 
	  Init:  Map<key,value> map = new HashMap<key,value>()   
		 map.put(key, value)  map.get(key)  map.containsKey(key)
       2. Understand the meaning of question. Say it with your words. 
public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int[] result = new int[2];
        
        for (int i = 0; i < numbers.length; ++i) {
            map.put(numbers[i], i);
        }
        
        for (int j = 0; j < numbers.length; ++j) {
            if (map.containsKey(target - numbers[j]) && 
                    map.get(target - numbers[j]) != j) {
                result[0] = Math.min(j, map.get(target - numbers[j])) + 1;
                result[1] = Math.max(j, map.get(target - numbers[j])) + 1;
                break;
            }
        }
        
        return result;
    }
}
