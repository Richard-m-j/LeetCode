class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1,n=nums.size();

        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                count++;
            }
            nums[count-1] = nums[i+1];
        }
        // if(n>=2 && nums[n-1] != nums[n-2]){
        //     count++;
        //     nums[count-1] = nums[n-1];
        // }
        return count;
    }
};