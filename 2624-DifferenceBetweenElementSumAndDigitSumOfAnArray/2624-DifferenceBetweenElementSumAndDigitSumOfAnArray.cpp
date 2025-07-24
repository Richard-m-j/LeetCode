// Last updated: 7/24/2025, 8:23:43 AM
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int e_sum=0,n=nums.size(),i;
        for(i=0;i<n;i++){
            e_sum+=nums[i];
            int d_sum=0;
            while(nums[i]>0){
                d_sum+=nums[i]%10;
                nums[i]/=10;
            }
            e_sum-=d_sum;
        }
        return e_sum;    
    }
};