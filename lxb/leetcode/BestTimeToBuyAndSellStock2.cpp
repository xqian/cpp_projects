http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

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
