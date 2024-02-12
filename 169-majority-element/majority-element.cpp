class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int& num : nums){
            cout<<mp[num]<<" ";
            mp[num]++;
            if(mp[num] > n/2)
                return num;
        }
        
        return nums[0];
    }
};