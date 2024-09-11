class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> res;
        int n = nums.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long newTarget = target - (long)nums[i] - (long)nums[j];

                int l=j+1,r=n-1;
                while(l<r){
                    if(nums[l]+nums[r] == newTarget){
                        res.insert({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                    }
                    else if(nums[l]+nums[r] < newTarget){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
            }
        }
        vector<vector<int>> result(res.begin(),res.end());
        return result;
    }
};