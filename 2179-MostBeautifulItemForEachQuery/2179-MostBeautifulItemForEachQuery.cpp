// Last updated: 7/24/2025, 8:25:08 AM
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        sort(items.begin(),items.end());
        map<int,int> mp;
        int maxBeauty = items[0][1];
        for(auto& item: items){
            maxBeauty = max(maxBeauty,item[1]);
            mp[item[0]]=maxBeauty;
        }
        
        for(int i=0;i<queries.size();i++){
            auto it = mp.lower_bound(queries[i]);
            if(it == mp.end())
                queries[i] = maxBeauty;
            else if(it->first ==queries[i])
                queries[i] = it->second;
            else{
                if(it == mp.begin())
                    queries[i]=0;
                else{
                    it--;
                    queries[i] = it->second;
                }
            }
        }
        return queries;
    }
};