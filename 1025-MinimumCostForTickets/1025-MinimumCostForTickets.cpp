// Last updated: 7/24/2025, 8:28:20 AM
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(367,0);
        unordered_set<int> days_set(days.begin(),days.end());
        for(int i=1;i<=366;i++){
            if(days_set.count(i))
                dp[i]=min({dp[i-1]+costs[0],dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]});
            
            else
                dp[i]=dp[i-1];
        }
        return dp[366];

    }
};