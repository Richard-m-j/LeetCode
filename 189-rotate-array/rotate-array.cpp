class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<int> right;
        int n = nums.size();
        if(k>n)
            k %= n;
        for(int i=n-k;i<n;i++)
            right.push_back(nums[i]),cout<<nums[i]<<" ";
        for(int i=n-1;i>=k;i--)
            nums[i] = nums[i-k],cout<<nums[i]<<" ";
        for(int i=0;i<k;i++)
            nums[i] = right[i];
    }
};