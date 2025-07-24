// Last updated: 7/24/2025, 8:36:41 AM
class Solution {
public:
    int maxArea(vector<int>& height) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int res = 0;
        int l=0,r=height.size()-1;
        while(l<r){
            int h = min(height[l],height[r]);
            int vol = (r-l)*h;
            res = max(res,vol);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return res;
    }
};