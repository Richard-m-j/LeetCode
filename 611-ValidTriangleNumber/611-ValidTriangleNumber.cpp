// Last updated: 7/24/2025, 8:30:10 AM
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=nums.size()-1;
        int ans=0;
        for(int i=s;i>=0;i--){
            int low =0;
            int high=i-1;
            while(low < high){
                if(nums[low] + nums[high] > nums[i]){
                    ans+=high-low;
                    high--;

                }
                else low++;

            }
        }
        return ans;
        
        
    }
};