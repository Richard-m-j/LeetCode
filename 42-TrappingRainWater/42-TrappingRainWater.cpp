// Last updated: 7/24/2025, 8:35:48 AM
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0), right(n, 0);
        left[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            left[i] = max(left[i - 1], height[i - 1]);
        }
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i + 1]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            int waterAbove = min(left[i],right[i]) - height[i];
            res += waterAbove>0?waterAbove:0;
        }
        return res;
    }
};