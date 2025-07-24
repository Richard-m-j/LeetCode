// Last updated: 7/24/2025, 8:24:09 AM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int maxi = *max_element(nums.begin(),nums.end());
        int res =0,curr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                curr++;
                res=max(res,curr);
            }
            else
                curr=0;
        }
        return res;
    }
};