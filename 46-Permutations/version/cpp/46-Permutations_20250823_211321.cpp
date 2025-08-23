// Last updated: 8/23/2025, 9:13:21 PM
class Solution {
private:
    void helper(vector<vector<int>>& res, vector<int> nums,int i){
        if(i==nums.size()){
            // cout<<nums.size()<<endl;
            res.push_back(nums);
            // cout<<res.size()<<endl;
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            helper(res, nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res,nums,0);
        return res;
    }
};