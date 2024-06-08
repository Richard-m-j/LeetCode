class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        if (nums.size() < 2)
            return false;
        std::unordered_map<int,int> mp;
        mp[0] = -1;
        int accumulated = 0;
        for (int i = 0; i < nums.size(); i++){
            accumulated += nums[i];
            int mod = accumulated % k;
            if(mod < 0) mod += k; 
            if(mp.find(mod) != mp.end()){
                if(i - mp[mod] > 1)
                    return true;
            }
            else
                mp[mod] = i;
        }    
        return false;
    }
};