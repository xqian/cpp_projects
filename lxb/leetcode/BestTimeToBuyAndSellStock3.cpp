http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> history(prices.size(), 0);
        vector<int> future(prices.size(), 0);
        
        //history
        int min = 0;
        for (int i=1; i<prices.size();i++){
            min = prices[i] < prices[min] ? i : min;
            history[i] = max (history[i-1], prices[i] - prices[min]);
        }
        
        //future
        int maxIndex = prices.size()-1;
        for (int j=prices.size()-2;j>=0;j--){
            maxIndex = prices[j] > prices[maxIndex] ? j :maxIndex;
            future[j] = max(future[j+1],prices[maxIndex] - prices[j]);
        }
        
        // find max(history[i] + future[i].
        int ret = 0;
        for (int i=0;i<prices.size();i++)
        {
            ret = max(ret, history[i]+future[i]);
        }
        
        return ret;
        
    }
};
