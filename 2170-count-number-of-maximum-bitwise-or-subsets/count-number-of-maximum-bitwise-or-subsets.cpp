class Solution {
private:
    int res;
    int maxBit;
    void helper(vector<int>& nums, int i, int bit){
        if(i==nums.size())
            return;
        if((bit | nums[i]) == maxBit)
            res++;
    
        helper(nums,i+1,bit | nums[i]);
        helper(nums,i+1,bit);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        maxBit = res = 0;
        for(int& num: nums)
            maxBit = maxBit | num;
        // cout<<maxBit<<" ";
        helper(nums,0,0);
        return res;
    }
};