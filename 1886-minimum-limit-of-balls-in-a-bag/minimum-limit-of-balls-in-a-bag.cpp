class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        while(l<r){
            int m = l + (r-l)/2;
            int numOps = 0;
            for(int& num: nums){
                numOps += (num-1)/m;
                if(numOps>maxOperations)
                    break;
            }
            if(numOps<=maxOperations)
                r=m;
            else
                l=m+1;
        }
        return r;
    }
};