// Last updated: 7/24/2025, 8:29:28 AM
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto &num:nums){
            mp[num]++;                                                
        }
        vector<pair<int,int>> weights (mp.begin(),mp.end());

        vector<int> dp(weights.size(),0);
        dp[0] = weights[0].second*weights[0].first;

        for(int i = 1;i<weights.size();i++){
            int points = weights[i].second * weights[i].first;
            if(weights[i].first == weights[i-1].first + 1){
                if(i>1)
                    points += dp[i-2];

                points = max(dp[i-1],points);
            }   
            else 
                points += dp[i-1];
            dp[i] = points;
        }
        return dp[dp.size()-1];
    }
};