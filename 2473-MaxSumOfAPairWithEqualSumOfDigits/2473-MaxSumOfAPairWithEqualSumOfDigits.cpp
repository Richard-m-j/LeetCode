// Last updated: 7/24/2025, 8:24:18 AM
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int res = -1;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int digitSum=0;
            while(num){
                digitSum+=num%10;
                num/=10;
            }
            if(mp.count(digitSum)){
                res = max(res,nums[i]+nums[mp[digitSum]]);
                if(nums[mp[digitSum]]<nums[i])
                    mp[digitSum] = i;
            }
            else
                mp[digitSum] = i;
        }
        return res;
    }
};