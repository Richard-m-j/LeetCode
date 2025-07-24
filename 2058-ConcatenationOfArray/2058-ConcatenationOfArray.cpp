// Last updated: 7/24/2025, 8:25:27 AM
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i< n;i++)
            nums.push_back(nums[i]);
        return nums;
    }
};