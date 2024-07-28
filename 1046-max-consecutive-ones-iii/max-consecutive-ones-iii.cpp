class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flip=k,l=0,r=0,res=0;
        while(r<nums.size()){
            if(!nums[r]){
                if(flip)
                    flip--;
                else{
                    while(nums[l++]);
                }
            }
            res = max(res,r-l+1);
            r++;
        }
        return res;
    }
};