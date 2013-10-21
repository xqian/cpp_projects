//http://oj.leetcode.com/problems/gas-station/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int leftGas = 0;   
        int gainGas = 0;
        int index = -1;
        
        for (int i=0; i< gas.size(); i++)
        {
            //check whether it's a solution.
            leftGas += gas[i] - cost[i];
            gainGas += gas[i] - cost[i];
            
            if (leftGas < 0) {
                leftGas = 0;
                index = i;
            }
        }
        
        return gainGas>=0? index+1 : -1;
    }
};
