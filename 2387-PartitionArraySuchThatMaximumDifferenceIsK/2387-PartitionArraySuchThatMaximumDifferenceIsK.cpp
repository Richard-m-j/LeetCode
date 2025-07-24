// Last updated: 7/24/2025, 8:24:30 AM
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=0;
        int n = nums.size();
        for(int i=0;i<n;){
            int minVal = nums[i];
            int maxVal = nums[i];
            while(++i<n){
                minVal = min(minVal,nums[i]);
                maxVal = max(maxVal,nums[i]);
                if(maxVal - minVal>k)
                    break;
            }
            res++;
        }
        return res;
    }
};