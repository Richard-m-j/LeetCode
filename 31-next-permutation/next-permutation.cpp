class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r=n-1;
        for(int i=n-2; i>-1;i--){
            if(nums[i]<nums[i+1]){
                l = i+1;
                for(int j=r;j>i;j--){
                    if(nums[j]>nums[i]){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }   
                break;
            }
        }
        while(l<r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }      
    }
};