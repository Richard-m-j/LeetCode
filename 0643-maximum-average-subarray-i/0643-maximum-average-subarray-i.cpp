class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n=nums.size();
        int max;
        int curr=0;
        for(int i=0;i<k;i++)
           curr+=nums[i];

        max=curr;
        for(int i=k;i<n;i++)
        {
            curr+=nums[i]-nums[i-k];
            if(max<curr)max=curr;
            
        }
        return static_cast<double>(max)/k;
    }
};