http://oj.leetcode.com/problems/two-sum/

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
