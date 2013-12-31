http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int min = 0;
        int maxDiff = 0;
        int buy = 0;
        int sell = 0;
        
        for (int i=0; i< prices.size(); i++){
             if (prices[i] < prices[min]) min = i;
             if (prices[i] - prices[min] > maxDiff){
                 maxDiff = prices[i] - prices[min];
                 buy = min;
                 sell = i;
             }
        }
        
        return maxDiff;
    }

}
