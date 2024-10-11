class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        helper(nums, 0);
        return res;
    }
    void helper(vector<int>& nums, int l) {
        if (l == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = l; i < nums.size(); i++) {
            swap(nums[l], nums[i]);
            helper(nums, l + 1);
            swap(nums[l], nums[i]);
        }
    }
};