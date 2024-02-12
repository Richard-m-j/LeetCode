class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int count = 0;
        int num;
        for (int i = 0; i < nums.size(); i++)
            if (count == 0) {
                num = nums[i];
                count++;
            } else if (num == nums[i])
                count++;
            else
                count--;
        return num;
    }
};