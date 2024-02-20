class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(10001);
        bool zero = false;
        for(int i =0;i<n;i++)
        {
            int num = abs(nums[i]);
            if(nums[num])
                nums[num] *= -1;
            else
                zero = true;
        }
        for(int i =0;i<n;i++)
            if(nums[i] == 0 && !zero)
                return i;
            else if(nums[i] > 0)
                return i;
        return n;
    }
};