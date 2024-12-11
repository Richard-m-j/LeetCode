class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l=0,r=0;
        int res=1;
        int k2=2*k;
        while(l<=r){
            while(r<n && abs(nums[r]-nums[l])<=k2){
                r++;
            }
            cout<<l<<" "<<r<<endl;
            res=max(res,r-l);
            l++;
        }
        return res;
    }
};