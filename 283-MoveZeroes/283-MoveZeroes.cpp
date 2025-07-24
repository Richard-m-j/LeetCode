// Last updated: 7/24/2025, 8:32:03 AM
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        int n=nums.size();
        ios_base::sync_with_stdio(false);

        for(int i=0;i<n;i++)
            if(nums[i])
                nums[j++]=nums[i];
        for(int i=j;i<n;i++)
            nums[i]=0;
    }
};