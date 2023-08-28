class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX;
        int b=INT_MAX;

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