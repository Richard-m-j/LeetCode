// Last updated: 7/24/2025, 8:36:05 AM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = nums.size();
        int l = 0,r=n-1;
        for (int i = n - 2; i > -1; i--) {
            if (nums[i] < nums[i + 1]) {
                l = i+1;
                // find next greatest element
                int nextIndex = i+1;
                for (int j = i+2; j < n; j++) {
                    if (nums[i] >= nums[j])
                        break;
                    nextIndex = j;
                }
                swap(nums[nextIndex],nums[i]);
                break;
            }
        }

        //reverse the remaining portion
        while(l<r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
};
// 1 2 3 4 7 5 1
// 1 2 3 5 7 4 1