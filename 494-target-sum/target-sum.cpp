class Solution {
private:
    int helper(vector<int>& nums, int target,int idx,int sum){
        if(idx==nums.size()){
            return sum==target;
        }
        int add = helper(nums,target,idx+1,sum+nums[idx]);
        int sub = helper(nums,target,idx+1,sum-nums[idx]);
        return add+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums,target,0,0);
    }
};