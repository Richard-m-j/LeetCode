class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map <int,int> hash;

        int n = nums.size();
        int sum{0};
        for(int i = n-1;i>=0;i--)
        {
            sum += nums[i];
            hash[sum] = i;
        }
        if(x > sum)
            return -1;
        sum = 0;
        int ans = INT_MAX;
        if(hash.find(x) != hash.end())
            ans = n - hash[x];
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            if(sum == x)
            {
                ans = min(i+1,ans);
            }
            if(hash.find(x - sum) == hash.end())
                continue;
            ans = min(i + 1 + n - hash[x-sum],ans);
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};