// Last updated: 7/24/2025, 8:29:54 AM
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int repeated;
        for(int num:nums)
        {
            if(nums[abs(num) -1] < 0)
                repeated = abs(num);
            else
                nums[abs(num) - 1] *= -1;
        }
        for(int i=0;i<n;i++)
            if(nums[i]>0)
                return {repeated,i+1};
        return {0,0};
    }
};