http://oj.leetcode.com/problems/gas-station/

/*
 Quesiton
 There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

Discuss


*/
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
