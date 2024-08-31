static const auto speedUp = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
private:
    void helper(vector<int>& candidates, int target,vector<vector<int>>& combinations,vector<int>& current, int n){
        if(target == 0){
            combinations.push_back(current);
            return;
        }
        for(int i=n;i<candidates.size();i++){
            if(i>n && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                break;
            current.push_back(candidates[i]);
            helper(candidates,target - candidates[i],combinations,current,i+1);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> current;
        helper(candidates,target,res,current,0);
        return res;
    }
};