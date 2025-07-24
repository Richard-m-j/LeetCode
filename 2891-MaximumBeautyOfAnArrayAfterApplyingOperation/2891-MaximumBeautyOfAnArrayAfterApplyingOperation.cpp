// Last updated: 7/24/2025, 8:23:01 AM
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l=0,r=0;
        int res=1;
        k*=2;
        while(l<=r){
            while(r<n && abs(nums[r]-nums[l])<=k){
                r++;
            }
            res=max(res,r-l);
            l++;
        }
        return res;
    }
};