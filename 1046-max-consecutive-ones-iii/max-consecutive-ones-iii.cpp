class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flip=k,l=0,res=0;
        for(int r=0;r<nums.size();r++){
            if(!nums[r]){
                if(flip)
                    flip--;
                else{
                    while(nums[l++]);
                }
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};