// Last updated: 7/24/2025, 8:22:41 AM
class Solution {
private:
    int numSetBits(int num){
        int x = 0;
        while(num){
            x += num&1;
            num = num>>1;
        }
        return x;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int prevL = INT_MIN, prevR = INT_MIN;
        for(int i=0;i<n;){
            int bits = numSetBits(nums[i]);
            // cout<<bits<<" ";
            int l=nums[i],r=nums[i];
            while(i<n && numSetBits(nums[i]) == bits){
                l  = min(l,nums[i]);
                r  = max(r,nums[i]);
                i++;
            }
            // cout<<prevR<<" ";
            // cout<<l<<" ";
            if(l<prevR)
                return false;
            prevR = r;
            
        }
        return true;
    }
};