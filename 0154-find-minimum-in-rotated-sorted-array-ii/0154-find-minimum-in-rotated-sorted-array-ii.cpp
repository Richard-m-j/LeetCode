class Solution {
public:
    int findMin(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
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
            else if(nums[l] == nums[m])
            {
                l++;
                if(nums[m] == nums[r])
                    r--;
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