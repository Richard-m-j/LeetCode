class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,int> mp;
        vector<vector<string>> res;
        int index =0;
        for(int i=0;i<strs.size();i++)
        {
            vector<int> mapping(26,0);
            for(char& c: strs[i])
                mapping[c-'a']++;
            if(mp.find(mapping)!=mp.end())
            {
                res[mp[mapping]].push_back(strs[i]);
            }
            else{
                mp[mapping] = index++;
                res.push_back({strs[i]});
            }
        }
        return res;
    }
};