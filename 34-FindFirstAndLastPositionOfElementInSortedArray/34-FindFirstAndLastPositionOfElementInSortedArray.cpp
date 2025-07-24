// Last updated: 7/24/2025, 8:35:58 AM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r= n-1;
        while(l<=r)
        {
            int m = l + (r - l) / 2;

            if(nums[m] == target)
            {
                l = m, r = m;
                while(l>=0 && nums[l] == target)
                    l--;
                while(r<n && nums[r] == target)
                    r++;
                return {l+1,r-1};
            }
            if(nums[m] < target)
                l = m+1;
            else
                r = m - 1;
        }
        return {-1,-1};
    }
};