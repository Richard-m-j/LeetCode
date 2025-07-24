// Last updated: 7/24/2025, 8:27:48 AM
class Solution {
private:
    struct pairHash{
        size_t operator()(const vector<int>& p) const{
            return hash<int>()(p[0]) ^ (hash<int>()(p[1]) << 1);
        }
    };
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<vector<int>,int,pairHash> mp;
        int res=0;
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i][0]>dominoes[i][1]){
                swap(dominoes[i][0],dominoes[i][1]);
            }
            if(mp.count(dominoes[i])){
                res+=mp[dominoes[i]];
            }
            mp[dominoes[i]]++;
        }
        return res;
        
    }
};