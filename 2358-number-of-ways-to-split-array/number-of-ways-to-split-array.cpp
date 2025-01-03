class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n),suffix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
            prefix[i] = prefix[i-1] + nums[i];
        suffix[n-1]=0;
        for(int i=n-2;i>=0;i--)
            suffix[i]=suffix[i+1] + nums[i+1];
        int res=0;
        for(int i=0;i<n-1;i++)
            if(prefix[i]>=suffix[i])
                res++;
        return res;
    }
};