// Last updated: 9/21/2025, 11:14:32 AM
class Solution {
private:
    vector<int> arr;
    void helper(int val) {
        int l = 0, r = arr.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (val > arr[m]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (l >= arr.size()) {
            arr.push_back(val);
        } else {
            arr[l] = val;
        }
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        arr.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            helper(nums[i]);
        }
        return arr.size();
    }
};