class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int l=0,r=0,mini=-1,maxi=-1;
        long long ans = 0;
        for(;r<nums.size();r++){
            if(nums[r]<minK || nums[r]>maxK){
                mini = maxi = -1;
                l = r+1;
            }
            if(nums[r] == minK)
                mini = r;
            if(nums[r] == maxK)
                maxi = r;
            ans += max(0,min(maxi,mini) - l + 1);
        }
        return ans;
    }
};