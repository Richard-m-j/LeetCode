// Last updated: 7/24/2025, 8:36:33 AM
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int closest = 0;
        int minDiff = INT_MAX;
        
        for (int i = 0; i < n - 2; ++i) {
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) 
                    return sum;
                
                int diff = abs(sum - target);
                
                if (diff < minDiff) {
                    minDiff = diff;
                    closest = sum;
                }
                
                if (sum < target) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        
        return closest;
    }
};
