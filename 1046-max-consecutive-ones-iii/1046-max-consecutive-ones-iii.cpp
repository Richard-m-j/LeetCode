class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int l = 0, r = 0, c = 0, cc = 0;
        while(r < nums.size()) {
            c += (nums[r] == 1 ? 0 : 1);
            while(c > k) c -= (nums[l] == 1 ? 0 : 1), l += 1;
            cc = max(cc, r-l+1);
            r += 1;
        }
        return cc;
    }
};