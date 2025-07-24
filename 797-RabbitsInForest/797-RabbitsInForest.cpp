// Last updated: 7/24/2025, 8:29:13 AM
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int& num: answers)
            mp[num]++;
        
        int res=0;
        for(auto& it: mp){
            if(it.second>it.first+1){
                res += ceil(it.second/(float)(it.first+1)) * (it.first+1);
            }
            else{
                res += it.first + 1;
            }
        }
        return res;
    }
};