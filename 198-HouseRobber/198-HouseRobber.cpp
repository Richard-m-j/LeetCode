// Last updated: 7/24/2025, 8:33:06 AM
class Solution {
private:
    vector<int> houses;
    vector<int> maxMoney;
public:
    int rob(vector<int>& nums) {
        houses = nums;
        maxMoney.resize(nums.size(),0);
        int i = 0;
        while(i<houses.size() && houses[i]==0)
            i++;
        int res = max(helper(i),helper(i+1));
        return res;
    }
    int helper(int i)
    {
        if(i > houses.size() - 1)
            return 0;
        if(maxMoney[i] != 0)
            return maxMoney[i];
        
        maxMoney[i] = houses[i] + max(helper(i+2),helper(i+3));
        return maxMoney[i];
    }
};