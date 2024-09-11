class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=0;
        int jumps= 0;
        while(r<n-1){
            int maxPos = l+nums[l];
            for(int i=l;i<=r;i++){
                maxPos = max(maxPos,nums[i]+i);
            }
            cout<<maxPos<<" ";
            jumps++;
            l=r;
            r=maxPos;
        }
        return jumps;
    }
};