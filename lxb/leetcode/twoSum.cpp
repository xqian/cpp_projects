http://oj.leetcode.com/problems/two-sum/
Question:
/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<int,int> hashTable;
        for (int i=0; i<numbers.size(); i++){
            hashTable[numbers[i]] = i;
        }
        
        vector<int> result;
        for (int i=0; i< numbers.size();i++){
            int expected = target - numbers[i];
            if (hashTable.count(expected) != 0 ){
                int index1 = i;
                int index2 = hashTable[expected];
                
                result.push_back(index1+1); //index is not zero based
                result.push_back(index2+1);
                break;
            }
        }
        
        return result;
    }
};
