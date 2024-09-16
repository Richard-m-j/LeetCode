class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int buy = INT_MIN;
        int sell = 0;
        for(int& price: prices){
            buy = max(buy,sell-price);
            sell = max(sell,buy+price-fee);
        }
        return sell;
    }
};