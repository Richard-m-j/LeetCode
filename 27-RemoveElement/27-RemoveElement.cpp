// Last updated: 7/24/2025, 8:36:13 AM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val)
                nums[j++] = nums[i];
        }
        return j;
    }
};