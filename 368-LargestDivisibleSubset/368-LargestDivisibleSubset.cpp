// Last updated: 7/24/2025, 8:31:35 AM
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1); // Stores the length of the largest divisible subset ending at index i
        vector<int> prevList(n, -1); // Stores the previous index
        
        int maxLen = 1, maxIndex = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prevList[i] = j;
                    if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }
        
        vector<int> res;
        while (maxIndex != -1) {
            res.push_back(nums[maxIndex]);
            maxIndex = prevList[maxIndex];
        }
        
        return res;
    }
};
