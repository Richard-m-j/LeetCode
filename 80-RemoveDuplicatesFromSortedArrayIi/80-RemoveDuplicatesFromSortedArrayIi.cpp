// Last updated: 7/24/2025, 8:34:59 AM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num = nums[0];
        int freq = 1;
        int k=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] != num){
                nums[k++] = nums[i];
                num = nums[i];
                freq = 1;
            }
            else if(nums[i] == num && freq< 2){
                nums[k++] = nums[i];
                freq++;
            }
            else 
                freq++;
            // cout<<freq<<" ";
        }
        return k;
    }
};