class Solution {
private:
    void backtracking(vector<int>& candidates, vector<vector<int>>& result, vector<int>& path, int idx, int target) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            path.push_back(candidates[i]);
            backtracking(candidates, result, path, i + 1, target - candidates[i]);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, result, path, 0, target);
        return result;
    }
};