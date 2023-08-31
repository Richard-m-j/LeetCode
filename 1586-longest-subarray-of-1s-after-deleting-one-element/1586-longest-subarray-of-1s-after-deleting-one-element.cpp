class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longest{0},left{0},curr{0},n=nums.size();
        int deleted=-1;
        for(int i=0;i<n&&deleted!=-1;i++)
            if(nums[i]==0)
            {
                deleted=i;
            }
        longest=deleted+1;
        for(int i=deleted +1 ;i<n;i++)
        {
            if(!nums[i])
            {
                left=deleted+1;
                deleted=i;
            }
            if(i-left>longest)
                longest=i-left;
            
        }
        return longest;
    }
};