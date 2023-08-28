class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> smaller(n);
        vector<int> larger(n);

        smaller[0]=nums[0];
        larger[n-1]=nums[n-1];

        for(int i=1;i<n;i++)
        {
            if(nums[i]<smaller[i-1])
                smaller[i]=nums[i];
            else
                smaller[i]=smaller[i-1];

            if(nums[n-i-1]>larger[n-i-1+1])
                larger[n-i-1]=nums[n-i-1];
            else
                larger[n-i-1]=larger[n-i-1+1];

        }
        
        

        // for(int i=n-2;i>=0;i--)
        //     if(nums[i]>larger[i+1])
        //         larger[i]=nums[i];
        //     else
        //         larger[i]=larger[i+1];

        for(int i=1;i<n-1;i++)
            if(smaller[i-1]<nums[i]&&larger[i+1]>nums[i])
                return true;
        return false;
    }
};