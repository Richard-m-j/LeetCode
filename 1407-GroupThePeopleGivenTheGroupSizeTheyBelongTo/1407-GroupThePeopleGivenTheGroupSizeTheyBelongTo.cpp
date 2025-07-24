// Last updated: 7/24/2025, 8:27:21 AM
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int,vector<int>> gp;
        int i=0;
        for(auto& it: groupSizes)
            gp[it].push_back(i++);

        for(auto& group: gp){
            vector<int> g;
            for(auto& num: group.second){
                if(g.size() == group.first){
                    res.push_back(g);
                    g={};
                }
                g.push_back(num);
            }
            if(g.size() == group.first){
                res.push_back(g);
                g={};
            }
        }
        return res;
    }
};