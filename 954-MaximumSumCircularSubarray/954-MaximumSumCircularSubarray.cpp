// Last updated: 7/24/2025, 8:28:39 AM
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int totalSum = 0, maxSum =nums[0],minSum = nums[0],currMax = 0,currMin = 0;
        for(int& num: nums){
            totalSum += num;
            currMax = max(currMax+num,num);
            maxSum = max(maxSum,currMax);
            currMin = min(currMin+num,num);
            minSum = min(minSum,currMin);
        }
        return maxSum>0?max(maxSum,totalSum-minSum):maxSum;
    }
};