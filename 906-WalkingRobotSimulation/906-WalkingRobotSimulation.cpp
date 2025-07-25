// Last updated: 7/24/2025, 8:28:54 AM
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
private:
    vector<pair<int, int>> dirs = {{0, 1},{1,0},{0,-1},{-1,0}};
    struct pairHash {
        size_t operator()(const pair<int, int>& p) const {
            return p.first ^ p.second;
        }
    };

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        pair<int, int> pos = {0, 0};
        unordered_set<pair<int,int>,pairHash> obstacleSet;

        for(auto& obstacle:obstacles)
            obstacleSet.insert({obstacle[0],obstacle[1]});

        int dirIndex = 0;
        int res = 0;
        for (auto& command : commands) {
            if (command == -2) 
                dirIndex = dirIndex>0?dirIndex-1:3;
            else if (command == -1) 
                dirIndex = dirIndex<3?dirIndex+1:0;
            else{
                int x = command * dirs[dirIndex].first;
                int y = command * dirs[dirIndex].second;

                for(int i=0;i<abs(x);i++){
                    pos.first += x>0?1:-1;
                    if(obstacleSet.find(pos) != obstacleSet.end()){
                        pos.first -= x>0?1:-1;
                        break;
                    }
                }
                for(int i=0;i<abs(y);i++){
                    pos.second += y>0?1:-1;
                    if(obstacleSet.find(pos) != obstacleSet.end()){
                        pos.second -= y>0?1:-1;
                        break;
                    }
                }
            }
            res = max(res, pos.first*pos.first + pos.second*pos.second);
        }
        return res;
    }
};