class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l{0}, r = nums.size() - 1, m;

        while(l <= r) {
            m = l+(r-l)/2;

            if(target == nums[m]) return true;

            if(nums[l] == nums[m] && nums[m] == nums[r]) {
                l++;
                r--;
                continue;
            }
            
            if(nums[l] <= nums[m]) {   //check if left half is sorted
                if(nums[l] <= target && target < nums[m]) r = m - 1;
                else l = m + 1;
            }

            if(nums[m] <= nums[r]) {   //check if right half is sorted
                if(nums[r] >= target && target > nums[m]) l = m + 1;
                else r = m - 1;
            }
        }
        return false;
    }
};