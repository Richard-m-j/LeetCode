// Last updated: 7/24/2025, 8:24:33 AM
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        vector<long long> prefix(n),suffix(n);
        
        suffix[n-1]=0;
        for(int i=n-2;i>=0;i--)
            suffix[i]=suffix[i+1] + nums[i+1];
        int res=0;
        prefix[0]=nums[0];  
        if(prefix[0]>=suffix[0])
            res++;          
        for(int i=1;i<n-1;i++){
            prefix[i] = prefix[i-1] + nums[i];
            if(prefix[i]>=suffix[i])
                res++;
        }
        return res;
    }
};