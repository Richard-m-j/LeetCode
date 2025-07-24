// Last updated: 7/24/2025, 8:28:44 AM
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<int,int> mp;
        for(int& num: deck){
            mp[num]++;
        }
        int minF=INT_MAX;
        for(auto&it: mp){
            minF=min(it.second,minF);
        }
        for(int i=2;i<=minF;i++){
            bool foundX=true;
            for(auto&it:mp){
                if(it.second%i){
                    foundX=false;
                    break;
                }
            }
            if(foundX)
                return true;
        }
        return false;
    }
};