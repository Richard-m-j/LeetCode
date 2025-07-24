// Last updated: 7/24/2025, 8:28:09 AM
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map <int,int> mp, mp1;
        if(n == 1 && trust.size() == 0)
            return 1;
        for(auto & t: trust){
            mp[t[1]]++;
            mp1[t[0]]++;

        }

        for(auto & it: mp){
            if(it.second == n - 1 && mp1[it.first] == 0)
                return it.first;
        }
        return -1;
    }
};