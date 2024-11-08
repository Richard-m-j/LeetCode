class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> xors(n+1,0);
        int maxNum = pow(2,maximumBit) - 1;
        for(int i=0;i<n;i++){
            xors[n-i-1] = xors[n-i] ^ nums[i];
        }
        for(int i=0;i<n;i++){
            xors[n-i-1] = xors[n-i-1] ^ maxNum;
        }
        xors.pop_back();
        return xors;
    }
};