class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        helper(nums, 0, n-1);
        return res;
    }
    void helper(vector<int>& nums, int l, int h) {
        if(l == h){
            res.push_back(nums);
            return;
        }
        for(int i=l;i<=h;i++){
            swap(nums,i,l);
            helper(nums,l+1,h);
            swap(nums,l,i);
        }
    }
    void swap(vector<int>&nums, int i, int j){
        int t= nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};