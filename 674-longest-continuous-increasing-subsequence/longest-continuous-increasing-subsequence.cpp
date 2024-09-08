class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1, curr = 1;
        ;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] > nums[i - 1]) {
                curr++;
                res = max(res, curr);
            } else
                curr = 1;
        return res;
    }
};