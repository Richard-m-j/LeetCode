int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
private:
    int n;
    void helper(unordered_map<int,int>& mp,vector<vector<int>>& res,vector<int>& current){
        if(current.size() == n)
            res.push_back(current);
        for(auto& it:mp){
            if(it.second){
                current.push_back(it.first);
                // cout<<it.first<<" ";
                mp[it.first]--;
                helper(mp,res,current);
                mp[it.first]++;
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        unordered_map<int,int> mp;
        for(int& num: nums)
            mp[num]++;
        vector<vector<int>> res;
        vector<int> current;
        helper(mp,res,current);
        return res;
        
    }
};