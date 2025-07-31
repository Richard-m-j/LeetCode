// Last updated: 7/31/2025, 6:01:24 PM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            while(i< nums.size() && i>0 && nums[i]==nums[i-1]){
                i++;
            }
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int val = nums[i] + nums[l] + nums[r];
                if(val==0){
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    while(l< nums.size() && nums[l]==nums[l-1]){
                        l++;
                    }
                }
                else if(val<0){
                    l++;
                    while(l< nums.size() && nums[l]==nums[l-1]){
                        l++;
                    }
                }
                else{
                    r--;
                    while(r>=0 && nums[r]==nums[r+1]){
                        r--;
                    }
                }
            }
        }
        return res;
    }
};