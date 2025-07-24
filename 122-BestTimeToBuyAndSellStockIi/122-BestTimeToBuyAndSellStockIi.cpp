// Last updated: 7/24/2025, 8:34:10 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[0];
        int res = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
                res += prices[i] - prices[i-1];
        }
        return res;
    }
};