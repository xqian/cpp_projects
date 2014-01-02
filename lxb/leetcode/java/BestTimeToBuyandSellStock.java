/*
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
//Focus: 1. Integer.MAX_VALUE, Integer.MIN_VALUE  2. boundary case (empty size, 1)  3. Java variable naming?
public class Solution {
    public int maxProfit(int[] prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int min_so_far = Integer.MAX_VALUE;
        int profit = 0;
        for (int i=0; i<prices.length;++i){
            if (min_so_far > prices[i]){
                min_so_far = prices[i];
            }
            
            if (profit < prices[i] - min_so_far) profit = prices[i] - min_so_far;
        }
        
        return profit;
    }
}
