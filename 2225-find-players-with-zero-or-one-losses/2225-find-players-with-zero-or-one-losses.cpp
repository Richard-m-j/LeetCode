int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map <int,int> losses;
        vector<int> noLoss;
        vector<int> oneLoss;
        set <int> players;
        for(const auto it: matches)
        {
            losses[it[1]]++;
            players.insert(it[0]);
            players.insert(it[1]);
        }
        for(const auto it: players)
        {
            if(losses[it] == 0)
                noLoss.push_back(it);
            else if(losses[it] == 1)
                oneLoss.push_back(it);
        }
        return {noLoss,oneLoss};
    }
};