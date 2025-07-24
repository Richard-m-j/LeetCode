// Last updated: 7/24/2025, 8:32:01 AM
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        for(int i=0;i<nums.size();i++){
            int num = abs(nums[i]);
            if(nums[num - 1]<0)
                return num;
            nums[num-1] *= -1;
        }
        return -1;
    }
};