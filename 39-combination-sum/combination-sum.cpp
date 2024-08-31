class Solution {
private:
    vector<vector<int>> res;
    vector<int> current;

    void helper(vector<int>& candidates, int target, int n){
        if(n<0 || target <0)
            return;
        if(target == 0)
            res.push_back(current);
        for(int i=n;i>=0;i--){
            current.push_back(candidates[i]);
            helper(candidates,target - candidates[i],i);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates,target,candidates.size()-1);
        return res;
    }
};