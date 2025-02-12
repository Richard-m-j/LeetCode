class Solution {
public:
    int maximumSum(vector<int>& nums) {
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