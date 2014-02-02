/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
public class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) return 0;
        
        int[] history = new int[prices.length];
        int[] future = new int[prices.length];
        
        int minHistory = prices[0];
        history[0] = 0;
        
        //history
        for (int i = 1; i < prices.length; ++i ) {
            if (minHistory > prices[i]) {
                minHistory = prices[i];
            }
            history[i] = Math.max(history[i - 1], prices[i] - minHistory);
        }
        
        //future
        int maxFuture = prices[prices.length - 1];
        future[prices.length -1] = 0;
        for (int j = prices.length - 2; j >= 0; --j) {
            if (maxFuture < prices[j]) {
                maxFuture = prices[j];
            }
            
            future[j] = Math.max(future[j + 1], maxFuture - prices[j]);
        }
        
        //find max (history[i] + future[i]);
        int maxProfit = 0;
        for (int k = 0; k < prices.length; ++k) {
            if (maxProfit < history[k] + future[k]) {
                maxProfit = history[k] + future[k];
            }
        }
        
        return maxProfit;
    }
}
