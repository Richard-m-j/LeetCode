class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,n=nums.size();
        int res = n+1, sum = nums[0];
        while(l<=r){
            while(r<n-1 && sum<target){
            cout<<sum<<"r ";
                r++;
                sum += nums[r];
            }
            while(l<=r && sum>=target){
                cout<<sum<<"l ";
                res = min(res,r-l+1);
                sum -= nums[l];
                l++;
            }
            cout<<sum<<" ";
            if(l<n)
                sum -= nums[l];
            l++;
        }
        if(res == n+1)
            return 0;
        return res;
    }
};