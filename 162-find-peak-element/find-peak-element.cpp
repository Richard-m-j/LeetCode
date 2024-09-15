class Solution {
private:
    bool isPeak(vector<int>& nums,int m){
        // cout<<m<<" ";
        if(m==0 && nums[m]>nums[m+1])
            return true;
        if(m==nums.size()-1 && nums[m]>nums[m-1])
            return true;
        if(m>0 && m<nums.size()-1 && nums[m]>nums[m+1] && nums[m]>nums[m-1])
            return true;
        return false;
    }
public:
    int findPeakElement(vector<int>& nums) {
        int n =nums.size();
        if(n==1)
            return 0;
        if(nums[0]>nums[1])
            return 0;
        if(nums[n-1]>nums[n-2])
            return n-1;
        int l = 1, r = n - 2;

        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]>nums[m-1]&&nums[m]>nums[m+1])
                return m;
            else if(nums[m]<nums[m-1])
                r=m-1;
            else
                l=m+1;
        }
        return -1;
    }
};