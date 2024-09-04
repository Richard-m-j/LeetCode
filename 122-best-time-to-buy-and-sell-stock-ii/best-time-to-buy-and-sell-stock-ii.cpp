int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        for(int i=1;i<prices.size();i++){
            int diff = prices[i]-prices[i-1];
            if(diff>0)
                res += diff;
        }
        return res;

    }
};