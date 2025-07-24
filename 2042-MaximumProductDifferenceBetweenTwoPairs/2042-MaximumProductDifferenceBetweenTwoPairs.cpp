// Last updated: 7/24/2025, 8:25:30 AM
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n =nums.size();

        sort(nums.begin(),nums.begin()+4);
        int a = nums[3];
        int b = nums[2];
        int c = nums[0];
        int d = nums[1];

        for(int i=4; i<n ; i++)
            if(nums[i] > a)
            {
                b = a;
                a = nums[i];
            }
            else if(nums[i] > b)
                b = nums[i];
            else if(nums[i] < c)
            {
                d = c;
                c = nums[i];
            }
            else if(nums[i] < d)
                d = nums[i];
        return a*b - c*d;
    }
};