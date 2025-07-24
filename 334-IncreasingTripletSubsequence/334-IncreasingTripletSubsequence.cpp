// Last updated: 7/24/2025, 8:31:48 AM
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX;
        int b=INT_MAX;
        ios_base::sync_with_stdio(false);

        for(auto num: nums)
            if(a>=num)
                a=num;
            else if(b>=num)
                b=num;
            else 
                return true;
        return false;
    }
};