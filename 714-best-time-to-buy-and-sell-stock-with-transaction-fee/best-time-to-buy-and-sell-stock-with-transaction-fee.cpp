class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int buy = prices[0];
        int sell = 0;
        for(int i=1;i<prices.size();i++){
            sell = max(sell,prices[i]-buy-fee);

            buy = min(buy,prices[i]-sell);
        }
        return sell;
    }
};