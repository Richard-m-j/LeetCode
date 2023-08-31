class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=nums.size();
        int left[n],right[n];
        left[0]=right[n-1]=0;

        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]+nums[i-1];
            right[n-i-1]=right[n-i]+nums[n-i];
        }
        for(int i=0;i<n;i++)
            if(left[i]==right[i])
                return i;

        
        return -1;
    }
};