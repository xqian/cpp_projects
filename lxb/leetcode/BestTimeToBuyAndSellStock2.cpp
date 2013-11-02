http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int sum = 0;
        
        int n = prices.size();
        if (n<2) return 0;
        
        for (int i=0; i<prices.size()-1;i++){
            if (prices[i] <= prices[i+1]){
               sum += prices[i+1] - prices[i];
            }
        }
        
        return sum;
    }
};
