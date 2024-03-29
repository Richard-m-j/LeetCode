auto init = []()
{
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);            
    cout.tie(nullptr);           
    return 'c';                  
}();
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int big = INT_MIN;
        for (auto& num : nums)
            big = max(big, num);
        long long ans = 0;
        int count = 0, l = 0;
        bool flag = false;
        for (int r = 0; r < nums.size(); r++) {
            count += nums[r] == big;
            while (count == k)
                count -= nums[l++] == big;
            ans += l;
        }
        return ans;
    }
};