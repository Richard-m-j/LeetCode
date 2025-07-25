// Last updated: 7/24/2025, 8:25:39 AM
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0, prev = 0, res = 0;
        for (int& num : nums) {
            if (num > prev)
                sum += num;
            else
                sum = num;
            res = max(res, sum);
            prev = num;
        }
        return res;
    }
};