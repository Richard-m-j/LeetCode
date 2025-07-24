// Last updated: 7/24/2025, 8:33:22 AM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++)
            if (count == 0) {
                num = nums[i];
                count++;
            } else if (num == nums[i])
                count++;
            else
                count--;
        return num;
    }
};