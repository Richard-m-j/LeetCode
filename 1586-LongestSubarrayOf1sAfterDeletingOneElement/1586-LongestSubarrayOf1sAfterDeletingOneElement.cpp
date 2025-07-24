// Last updated: 7/24/2025, 8:26:32 AM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int longest{0},left{0},n=nums.size();
        int deleted=-1;
        
        for(int i=0 ;i<n;i++)
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