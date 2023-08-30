class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int max;
        int curr=0;
        for(int i=0;i<k;i++)
        {
           curr+=nums[i];
        }
        max=curr;
        for(int i=k;i<n;i++)
        {
            curr+=nums[i]-nums[i-k];
            max=curr>max?curr:max;
            
        }
        return (double)max/k;
    }
};