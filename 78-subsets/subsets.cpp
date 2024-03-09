class Solution {
    vector<vector<int>> res;
    vector<int> nums;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        Solution::nums = nums;
        vector<int> sub;
        helper(sub,0);
        return res;
    }
    void helper(vector<int>& subset, int index){
        res.push_back(subset);
        for(int i = index; i< nums.size();i++)
        {
            subset.push_back(nums[i]);
            helper(subset,i+1);
            subset.pop_back();
        }
    }
};