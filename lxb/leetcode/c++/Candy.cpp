http://oj.leetcode.com/problems/candy/

/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int sum = 0;
        int n = ratings.size();
        
        //at least one for each 
        vector<int> num(n,1);
        
        // left to right fix
        for (int i=1;i<n;i++)
        {
            if (ratings[i] > ratings[i-1])
                num[i] = num[i-1] + 1;
        }
        
        // right to left fix
        for (int j=n - 2;j>=0;j--){
            if (ratings[j] > ratings[j+1])
                num[j] = max(num[j], num[j+1]+1);
        }
        
        //now we get it.
        for (int i=0;i<n;i++) sum += num[i];
        
        return sum;
    }
};
