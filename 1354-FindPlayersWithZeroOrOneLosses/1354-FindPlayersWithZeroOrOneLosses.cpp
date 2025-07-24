// Last updated: 7/24/2025, 8:27:33 AM
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> losses(100001, -1);
        
        for(auto& m : matches) 
        {
            if(losses[m[0]] == -1)
                losses[m[0]] = 0;
            if(losses[m[1]] == -1)
                losses[m[1]] = 1;
            else
                losses[m[1]]++;
        }
        vector<vector<int>> ans(2);
        
        for(int i = 1; i< 100001; i++) 
            if(losses[i] == 0)
                ans[0].push_back(i);
            else if (losses[i] == 1)
                ans[1].push_back(i);
        return ans;
    }
};