class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);

        int numZero=k,n=nums.size(),longest{0},curr{0};

        for(int i=0;i<n;i++)
        {
            if(!nums[i])
            {
                if(numZero>0)
                    curr++,numZero--;
                else
                {
                    while(nums[i-curr])
                        curr--;
                }
            }
            else 
                curr++;
            if(longest<curr)
                longest =curr;
        }
        return longest;
    }
};