// Last updated: 7/24/2025, 8:34:08 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            buy = min(buy,prices[i]);
            // sell = max(sell,prices[i]);
            if(prices[i]>buy)
                profit = max(profit,prices[i]-buy);
        }
        return profit;
    }
};