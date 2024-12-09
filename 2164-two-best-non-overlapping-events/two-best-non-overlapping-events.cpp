class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> dp;
        for(auto& event: events){
            dp.push_back(event);
            dp.push_back({event[1]+1,0,event[2]});
        }
        sort(dp.begin(),dp.end());
        int res=0;
        int maxFinished = 0;
        for(auto& event: dp){
            if(event[1]!=0){
                res = max(res,maxFinished+event[2]);
            }
            else{
                maxFinished = max(maxFinished,event[2]);
            }
        }
        return res;
    }
};