class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int longest{0},left{0},n=nums.size();
        int deleted=-1;
        
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