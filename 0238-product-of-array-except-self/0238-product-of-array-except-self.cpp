class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
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
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> ans(n,1);

//         int leftProduct=1;
//         for(int i=0;i<n;i++)
//         {
//             ans[i]=leftProduct;
//             leftProduct*=nums[i];
//         }
//         int rightProduct=1;
//         for(int i=n-1;i>=0;i--)
//         {
//             ans[i]*=rightProduct;
//             rightProduct*=nums[i];
//         }

//         return ans;
        
//     }
// };