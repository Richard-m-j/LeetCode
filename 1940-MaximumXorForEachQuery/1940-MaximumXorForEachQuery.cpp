// Last updated: 7/24/2025, 8:25:38 AM
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> xors(n,0);
        int maxNum = pow(2,maximumBit) - 1;
        xors[n-1] = nums[0];
        for(int i=1;i<n;i++)
            xors[n-i-1] = xors[n-i] ^ nums[i];
        
        for(int i=0;i<n;i++)
            xors[n-i-1] ^= maxNum;
        
        return xors;
    }
};