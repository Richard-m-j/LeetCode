// Last updated: 7/24/2025, 8:33:39 AM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r= nums.size()-1,mini = nums[0];
        
        while(l <= r)
        {
            int m = l + (r-l)/2;
            mini = min(nums[m],mini);
            if(nums[l] < nums[m])
            {
                mini = min(nums[l],mini);
                l= m+1;
            }
            else
            {
                mini = min(nums[r],mini);
                r= m-1;
            }
        }
        return mini;
    }
};