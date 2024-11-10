class Solution {
private: 
    int bitsToNum(vector<int>& bits){
        int num = 0;
        long pow = 1;
        for(int i = 0; i < bits.size(); i++){
            num += (bits[i] > 0 ? 1 : 0) * pow;
            pow *= 2;
        }
        return num;
    }

    void update(vector<int>& bits, int num, int change){
        int bit = 1;
        for(int i = 0; i < 32; i++){
            if(num & bit)
                bits[i] += change;
            bit <<= 1;
        }
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        int res = n + 1;
        vector<int> bits(32, 0);
        int l = 0, r = 0;
        int curr = 0;

        while (l <= r && r < n) {
            if (nums[r] >= k)
                return 1;
            while (r < n && curr < k) {
                update(bits, nums[r], 1);
                curr = bitsToNum(bits);
                r++;
            }
            while (l < r && curr >= k) {
                res = min(res, r - l);
                update(bits, nums[l], -1);
                curr = bitsToNum(bits);
                l++;
            }
        }
        return res == n + 1 ? -1 : res;
    }
};
