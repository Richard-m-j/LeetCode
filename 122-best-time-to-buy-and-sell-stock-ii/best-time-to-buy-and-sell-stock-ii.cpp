int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int notHold = 0;

        for(int i=0;i<prices.size();i++){
            int prevHold = hold;
            int prevNotHold = notHold;

            hold = max(hold, prevNotHold - prices[i]);
            notHold = max(notHold, prevHold + prices[i]);
        }
        return notHold;

    }
};