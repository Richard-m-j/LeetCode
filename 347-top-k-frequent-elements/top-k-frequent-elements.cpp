class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &num:nums)
            mp[num]++;
        vector<pair<int,int>> mpVec (mp.begin(),mp.end());
        sort(mpVec.begin(),mpVec.end(),[](const auto &a, const auto &b){
            return a.second>b.second;
        });
        vector<int> res;
        for(int i=0;i<k;i++)
            res.push_back(mpVec[i].first);
        return res;
    }
};