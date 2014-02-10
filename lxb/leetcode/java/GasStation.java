/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/
Focus 1: Array.length , index start from 1.
      2. O(n)

public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int gainGas = 0;
        int leftGas = 0;
        int startIndex = 0;
        
        for (int i = 0; i < gas.length; ++i) {
            gainGas += gas[i] - cost[i];
            leftGas += gas[i] - cost[i];
            
            if (leftGas < 0) {
                leftGas = 0;
                startIndex = (i + 1) % gas.length;
            }
        }
        
        if (gainGas < 0) {
            return -1;
        }
        
        return startIndex;
    }
}
