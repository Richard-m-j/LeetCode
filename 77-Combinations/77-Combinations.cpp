// Last updated: 7/24/2025, 8:35:03 AM
class Solution {
private: 
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        combinations(n,comb,1,k);
        return res;
    }
    void combinations(int n,vector<int> comb, int l,int k){
        if(comb.size()==k){
            res.push_back(comb);
            return;
        }
        for(int i=l;i<=n;i++){
            comb.push_back(i);
            combinations(n,comb,i+1,k);
            comb.pop_back();
        }
    }
};