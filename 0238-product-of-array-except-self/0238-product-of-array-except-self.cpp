class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        product(1,0,nums,ans);

        return ans;
    }
    int product(int leftProduct,int key,vector<int> &nums,vector<int> &ans)
    {
        int rightProduct;
        if(key==nums.size()-1)
            rightProduct=1;
        else
            rightProduct=product(leftProduct*nums[key],key+1,nums,ans);

        ans[key]=leftProduct*rightProduct;

        return nums[key]*rightProduct;
        
    }
};