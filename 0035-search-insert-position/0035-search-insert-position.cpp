class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int u=nums.size()-1;
        int m;
        while(l<=u){
            m=l+(u-l)/2;
            if(nums[m]<target)
                l=m+1;
            else if(nums[m]>target)
                u=m-1;
            else
                return m;
        }
        return l;
    }
};