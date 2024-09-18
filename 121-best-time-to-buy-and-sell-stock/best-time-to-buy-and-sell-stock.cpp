class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int buy = prices[0];
        int sell = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            sell = max(sell,prices[i] - buy);
            buy = min(buy,prices[i]);
        }
        return sell;
    }
};