// Last updated: 7/24/2025, 8:29:25 AM
static const int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
private: 
    vector <int> cost;
    vector<int> dp;
public:
    int minCostClimbingStairs(vector<int>& c) {
        cost = c;
        dp.resize(cost.size());
        int res = min(helper(0),helper(1));
        return res;
    }
    int helper(int index)
    {
        if(index >= cost.size())
            return 0;
        if(dp[index]!=0)
            return dp[index];
        dp[index] = cost[index] + min(helper(index+1),helper(index+2));
        return dp[index];
    }
    
};