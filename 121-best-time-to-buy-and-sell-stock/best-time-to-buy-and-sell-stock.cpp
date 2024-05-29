class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[buy])
                buy = i;
            if (sell < buy || prices[sell] < prices[i])
                sell = i;
            profit =
                sell > buy ? max(profit, prices[sell] - prices[buy]) : profit;
        }
        return profit;
    }
};